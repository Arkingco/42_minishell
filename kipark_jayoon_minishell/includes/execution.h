/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:37:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/26 16:08:41 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
# include "parser.h"

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
void	process_execve_args(t_parsing_list *l_parsing, t_args_execve *p_args,
			t_env *l_env);
char	**init_curr_envp(t_env *l_env);

// utils
int		is_single_cmd(t_parsing_list *next);

#endif
