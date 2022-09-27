/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:37:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/27 14:49:51 by jayoon           ###   ########.fr       */
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
}	t_args_execve;

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
