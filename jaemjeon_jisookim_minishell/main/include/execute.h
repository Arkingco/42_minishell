/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 10:46:02 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "structs/t_working_dir.h"
# include "structs/t_env.h"
# include "structs/t_cmd.h"

# define INPUT_REDI			2
# define OUTPUT_REDI		3
# define INPUT_PIPE			INPUT_REDI
# define OUTPUT_PIPE		OUTPUT_REDI
# define RESTORE_PIPE		RESTORE_REDI
# define MULTI_PIPE_OUTPUT	0
# define MULTI_PIPE_INPUT	1
# define BEFORE_INPUT_FD	2

// exec_built_in
int		process_built_in(t_cmd *cmd, t_working_info *info, int cmd_type);
void	process_not_built_in(t_working_info *info);

// exec_do
void	single_cmd_child_process(t_working_info *info);
void	exec_executing(t_working_info *info);
int		ft_wait_childs(pid_t *child_pids, int cmd_count);

// exec_file
int		open_infile(t_cmd *cmd);
int		open_outfile(t_cmd *cmd);
int		check_and_get_infile(t_token *input);
int		check_and_get_outfile(t_token *output);

// exec_ft_tools
int		ft_close(int fd);
pid_t	ft_fork(void);
pid_t	ft_wait(int count, pid_t *child_pids);
int		ft_dup2(int fd1, int fd2);
int		ft_pipe(int *pipe_fd);

// exec_path_expand
// void	expand_homepath(char **cmd_string, t_working_info *info);
// int		expand_homepath_and_check_is_there(t_cmd *cmd, t_working_info *info);

// exec_path
char	**get_path_board(t_envlst *env);
int		is_already_exec_path(char *cmd_string);
int		is_valid_cmd_path(char *cmd_string);
int		set_absolute_path(t_cmd *cmd, t_working_info *info);
int		set_exec_path(t_cmd *cmd, t_working_info *info);

// exec_pipe
void	init_pipe_before_next_cmd(t_cmd *cur_cmd, int *fd);

// exec_redirect
void	handle_redirect_input(t_token *input_redirection);
void	handle_redirect_output(t_token *output_redirection);
void	handle_redirection_multi_cmd(t_cmd *cmd);
void	restore_redirect_fd(t_cmd *cmd, int *io_fd);
int		process_redirect(t_cmd *cmd, int *io_fd);

// exec_utils
int		get_cmd_type(t_cmd *cmd);
char	**get_exec_argv(t_cmd *cmd);
void	close_useless_fds(int *fd);

// execute
void	process_single_cmd(t_working_info *info);
void	execute_multicmd_child(t_working_info *info, t_cmd *my_cmd, int *fd);
pid_t	process_multi_cmd(t_working_info *info);
void	execute(t_working_info *info);

#endif
