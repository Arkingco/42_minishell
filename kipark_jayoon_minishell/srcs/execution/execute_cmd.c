/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 17:36:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"
#include "here_doc.h"

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

static void	init_valiable(int *fd, t_info_cmd *info_cmd,
				t_parsing_list *l_parsing, t_env **l_env)
{
	*l_env = (*l_env)->next;
	info_cmd->l_here_doc = info_cmd->l_here_doc->next;
	init_std_fd(fd);
	info_cmd->idx_curr_proc = 0;
	info_cmd->num_proc = count_the_number_of_processes(l_parsing);
	info_cmd->args_execve.envp = init_curr_envp(*l_env);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_info_cmd		info_cmd;
	t_here_doc		*head_here_doc;
	int				fd[3];

	info_cmd.l_here_doc = init_here_doc(l_parsing);
	if (info_cmd.l_here_doc == NULL)
		return ;
	print_here_doc(info_cmd.l_here_doc);
	head_here_doc = info_cmd.l_here_doc;
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
		execute_bulit_in(l_parsing->l_simple_cmd, l_env, SINGLE_CMD);
	else
	{
		init_valiable(fd, &info_cmd, l_parsing, &l_env);
		while (l_parsing)
		{
			if (l_parsing->next)
				safe_pipe(fd);
			info_cmd.pid = safe_fork();
			if (info_cmd.pid == 0)
				do_it_child(l_parsing, &info_cmd, fd);
			else
				do_it_parent(l_parsing->redir_iter, fd, &info_cmd);
			info_cmd.idx_curr_proc++;
			l_parsing = l_parsing->next;
		}
		wait_all_child(info_cmd.pid, info_cmd.num_proc);
		ft_safe_free(info_cmd.args_execve.envp);
	}
	free_all_here_doc(head_here_doc, 0);
}
