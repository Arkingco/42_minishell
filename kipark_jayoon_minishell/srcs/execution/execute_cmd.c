/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 18:01:02 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"
#include "here_doc.h"
#include "terminal.h"

static void	init_std_fd(int *fd)
{
	fd[0] = 0;
	fd[1] = 1;
	fd[2] = 0;
}

static void	init_valiable(int *fd, t_info_cmd *info_cmd,
				t_parsing_list *l_parsing, t_env *l_env)
{
	if (l_parsing->redir_iter)
		info_cmd->this_l_input = l_parsing->redir_iter->l_input;
	else
		info_cmd->this_l_input = NULL;
	info_cmd->l_here_doc = info_cmd->l_here_doc->next;
	init_std_fd(fd);
	info_cmd->idx_curr_proc = 0;
	info_cmd->num_proc = count_num_processes(l_parsing);
	info_cmd->args_execve.envp = init_curr_envp(l_env->next);
}

static void	run_multi_cmd(t_parsing_list *l_parsing, int *fd, \
											t_info_cmd *info_cmd, t_env *l_env)
{
	while (l_parsing)
	{
		if (l_parsing->next)
			safe_pipe(fd);
		info_cmd->pid = safe_fork();
		if (info_cmd->pid == 0)
			do_it_child(l_parsing, info_cmd, fd, l_env);
		else
			do_it_parent(fd, info_cmd);
		info_cmd->idx_curr_proc++;
		l_parsing = l_parsing->next;
		if (l_parsing && l_parsing->redir_iter)
			info_cmd->this_l_input = l_parsing->redir_iter->l_input;
		else
			info_cmd->this_l_input = NULL;
	}
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_info_cmd		info_cmd;
	t_here_doc		*head_here_doc;
	int				fd[3];

	info_cmd.l_here_doc = init_here_doc(l_parsing);
	if (info_cmd.l_here_doc == NULL)
		return ;
	head_here_doc = info_cmd.l_here_doc;
	init_valiable(fd, &info_cmd, l_parsing, l_env);
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
		run_single_built_in(l_parsing, &info_cmd, fd, l_env);
	else
	{
		init_terminal(EXECUTE_TERMINAL);
		run_multi_cmd(l_parsing, fd, &info_cmd, l_env);
		wait_all_child(info_cmd.pid, info_cmd.num_proc);
		init_terminal(DEFAULT_TERMINAL);
	}
	ft_safe_free(info_cmd.args_execve.envp);
	free_all_here_doc(head_here_doc, 0);
}
