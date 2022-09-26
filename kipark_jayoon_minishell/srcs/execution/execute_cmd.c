/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/26 20:32:23 by jayoon           ###   ########.fr       */
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
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(p_args->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_safe_free_two_dimentions_arr(p_args->path);
	ft_safe_free_two_dimentions_arr(p_args->argv);
	exit(127);
}

static void	do_it_child(t_parsing_list *l_parsing, t_args_execve *p_args_execve,
	t_env *l_env, char **envp)
{
	init_execve_args(l_parsing, p_args_execve, l_env);
	execve_cmd(p_args_execve, envp);
}

static void	safe_pipe(int *fd)
{
	int	ret;

	ret = pipe(fd);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	char			**curr_envp;
	pid_t			pid;
	int				pipefd[2];
	size_t			num_process;
	
	num_process = 0;
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, l_env, SINGLE_CMD);
	}
	else
	{
		l_env = l_env->next;
		curr_envp = init_curr_envp(l_env);
		safe_pipe(pipefd);
		while (l_parsing)
		{
			pid = safe_fork();
			// pipe 넣기
			if (pid == 0)
				do_it_child(l_parsing, &args_execve, l_env, curr_envp);
			// else
				// do_it_parent();
			num_process++;
			l_parsing = l_parsing->next;
		}
		wait_all_child(pid, num_process);
		ft_safe_free(curr_envp);
	}
}
