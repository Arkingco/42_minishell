/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:37:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/27 21:29:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
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

typedef struct s_info_fd
{
	t_fd_using_dup2	updated_fd;
	int				pipefd[2];
}	t_info_fd;

typedef struct s_info_process
{
	pid_t	pid;
	size_t	idx_curr_proc;
	size_t	num_proc;
}	t_info_process;

// main
void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env);
void	init_execve_args(t_parsing_list *l_parsing, t_args_execve *p_args,
			char **envp);

char	**init_curr_envp(t_env *l_env);

/* safe func */
int		safe_fork(void);

/* wait */
void	wait_all_child(pid_t last_fork_pid, size_t num_process);

// utils
int		is_single_cmd(t_parsing_list *next);

#endif
