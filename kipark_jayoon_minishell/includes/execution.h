/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:37:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/26 14:18:04 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
# include "parser.h"

typedef struct s_args_execve
{
	char	**path;
	char	**argv;
}	t_args_execve;

// main
void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env);
void	init_execve_args(t_parsing_list *l_parsing, t_args_execve *p_args,
			t_env *l_env);
char	**init_curr_envp(t_env *l_env);

/* safe func */
int				safe_fork(void);

// utils
int		is_single_cmd(t_parsing_list *next);

#endif
