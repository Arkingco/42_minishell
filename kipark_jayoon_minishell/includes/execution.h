/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:37:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 18:00:03 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
# include "here_doc.h"
# include "parser.h"
# include <stdlib.h>

typedef enum e_execute_cmd_division
{
	SINGLE_CMD,
	MULTI_CMD
}	t_execute_cmd_division;

typedef struct s_args_execve
{
	char	**path;
	char	**argv;
	char	**envp;
}	t_args_execve;

typedef struct s_fd_using_dup2
{
	int	input;
	int	output;
}	t_fd_using_dup2;

typedef struct s_info_cmd
{
	pid_t			pid;
	size_t			idx_curr_proc;
	size_t			num_proc;
	t_args_execve	args_execve;
	t_here_doc		*l_here_doc;
	t_redir_chunk	*this_l_input;
}	t_info_cmd;

/* main */
void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env);
void	init_execve_args(t_parsing_list *l_parsing, t_args_execve *p_args,
			char **envp);
void	do_it_parent(int *fd, t_info_cmd *info_cmd);
void	do_it_child(t_parsing_list *l_parsing, t_info_cmd *info_cmd, \
													int *fd, t_env *l_head_env);
char	**init_curr_envp(t_env *l_env);
void	init_fd_by_redirection(t_redir_iter *redir_iter, int *fd,
			t_here_doc *l_here_doc);
int		parent_init_fd_redir(t_redir_iter *redir_iter, int *fd,
			t_here_doc *l_here_doc);
void	execve_cmd(t_args_execve *p_args, char **envp);
void	run_single_built_in(t_parsing_list *l_parsing, t_info_cmd *info_cmd, \
													int *fd, t_env *l_head_env);

/* safe func */
int		safe_fork(void);
void	safe_close(int fd);
void	safe_dup2(int from, int to);
void	safe_dup2_and_close(int from, int to);
int		safe_open(char *path, int oflag);
void	safe_pipe(int *fd);

/* wait */
void	wait_all_child(pid_t last_fork_pid, size_t num_process);

/* utils */
size_t	count_num_processes(t_parsing_list *l_parsing);
int		is_single_cmd(t_parsing_list *next);
int		is_last_cmd(t_info_cmd *info_cmd);

#endif
