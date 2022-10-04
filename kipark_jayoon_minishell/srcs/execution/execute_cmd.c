/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/04 16:56:44 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"
#include "here_doc.h"

// printf
#include <stdio.h>

static size_t	count_the_number_of_processes(t_parsing_list *l_parsing)
{
	size_t	num;

	num = 0;
	while (l_parsing)
	{
		num++;
		l_parsing = l_parsing->next;
	}
	return (num);
}

static void	init_std_fd(int *fd)
{
	fd[0] = 0;
	fd[1] = 1;
	fd[2] = 0;
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	t_info_process	info_proc;
	t_here_doc		*l_here_doc;
	int				fd[3];

	l_here_doc = init_here_doc(l_parsing);
	if (l_here_doc == NULL)
		return ;
	print_here_doc(l_here_doc);
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
		execute_bulit_in(l_parsing->l_simple_cmd, l_env, SINGLE_CMD);
	else
	{
		init_std_fd(fd);
		info_proc.idx_curr_proc = 0;
		info_proc.num_proc = count_the_number_of_processes(l_parsing);
		l_env = l_env->next;
		args_execve.envp = init_curr_envp(l_env);
		while (l_parsing)
		{
			if (l_parsing->next)
				safe_pipe(fd);
			info_proc.pid = safe_fork();
			if (info_proc.pid == 0)
				do_it_child(l_parsing, &args_execve, fd, &info_proc);
			else
				do_it_parent(fd, &info_proc);
			info_proc.idx_curr_proc++;
			l_parsing = l_parsing->next;
		}
		wait_all_child(info_proc.pid, info_proc.num_proc);
		ft_safe_free(args_execve.envp);
	}
	free_all_here_doc(l_here_doc, 0);
}
