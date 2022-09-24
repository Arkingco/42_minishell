/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 22:21:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"

// printf
#include <stdio.h>

static void	execve_cmd(t_args_execve *p_args, char **envp)
{
	size_t	i;
	char	*file_path;

	i = 0;
	while (p_args->path[i])
	{
		file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
		execve(file_path, p_args->argv, envp);
		ft_safe_free(file_path);
		i++;
	}
	ft_safe_free_two_dimentions_arr(p_args->path);
	ft_safe_free_two_dimentions_arr(p_args->argv);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(p_args->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	char			**curr_envp;
	
	printf("\n*exeuction*\n");
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, l_env);
	}
	else
	{
		printf("single & multi shell cmd\n\n");
		l_env = l_env->next;
		curr_envp = init_curr_envp(l_env);
		while (l_parsing)
		{
			process_execve_args(l_parsing, &args_execve, l_env);
			execve_cmd(&args_execve, curr_envp);
			l_parsing = l_parsing->next;
		}
		ft_safe_free(curr_envp);
	}
	printf("----------------------------------------\n\n\n");
}
