/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 18:29:10 by jisookim         ###   ########.fr       */
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

// exec_d
void	exec_executing(t_working_info *info);
int		ft_wait_childs(pid_t *child_pids, int cmd_count);

// exec_file
int		open_infile(t_cmd *cmd);
int		open_infile_check_next(t_token *redircet_token, int infile_fd);
int		open_outfile(t_cmd *cmd);
void	open_outfile_check_next(t_token *redircet_token, int outfile_fd, \
															int open_option);

// exec_file_check
int		check_and_get_infile(t_token *input);
int		check_and_get_outfile(t_token *output);

// exec_ft_tools
int		ft_close(int fd);
pid_t	ft_fork(void);
pid_t	ft_wait(int count, pid_t *child_pids);
int		ft_dup2(int fd1, int fd2);
int		ft_pipe(int *pipe_fd);

// exec_multi_child.c
void	handle_redi_multicmd_child(int *fd, t_cmd *my_cmd);
void	execute_multicmd_child(t_working_info *info, t_cmd *my_cmd, int *fd);

// exec_multi.c
pid_t	*init_exec_multi(t_working_info *info, int fd[], \
											pid_t *child_pids, t_cmd *cur_cmd);
int		handle_wait_status(pid_t *child_pids, t_working_info *info, pid_t pid);
pid_t	process_multi_cmd(t_working_info *info, int fd[]);

// exec_path
char	**get_path_board(t_envlst *env);
int		is_already_exec_path(char *cmd_string);
int		is_valid_cmd_path(char *cmd_string);
int		set_absolute_path(t_cmd *cmd, t_working_info *info);
int		set_exec_path(t_cmd *cmd, t_working_info *info);

// exec_pipe
void	init_pipe_before_next_cmd(t_cmd *cur_cmd, int *fd);

// exec_redirect_handler
void	handle_redirect_input(t_token *input_redirection);
void	handle_redirect_output(t_token *output_redirection);
void	handle_redirection_multi_cmd(t_cmd *cmd);

// exec_redirect
void	restore_redirect_fds(t_cmd *cmd, int *io_fd);
void	dup2_io_fd(int *io_fd);
int		process_redirect(t_cmd *cmd, int *io_fd);

// exec_utils
int		get_cmd_type(t_cmd *cmd);
char	**get_exec_argv(t_cmd *cmd);
void	close_useless_fds(int *fd);

// execute
void	process_single_cmd(t_working_info *info);
void	execute(t_working_info *info);

#endif
