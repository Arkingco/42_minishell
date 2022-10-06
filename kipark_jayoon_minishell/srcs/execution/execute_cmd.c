/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 15:33:31 by kipark           ###   ########seoul.kr  */
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

void	run_single_built_in(t_parsing_list *l_parsing, t_info_cmd *info_cmd, \
													int *fd, t_env *l_head_env)
{
	int temp_fd[2];

	temp_fd[0] = 257;
	temp_fd[1] = 258;
	safe_dup2(0, temp_fd[0]);
	safe_dup2(1, temp_fd[1]);
	if (l_parsing->redir_iter)
		init_fd_by_redirection(l_parsing->redir_iter, fd, info_cmd->l_here_doc);
	if (fd[0] != 0 && info_cmd->idx_curr_proc != info_cmd->num_proc - 1)
		safe_close(fd[0]);
	if (fd[1] != 1)
	{
		safe_dup2(fd[1], 1);
		safe_close(fd[1]);
	}
	if (fd[2] != 0)
	{
		safe_dup2(fd[2], 0);
		safe_close(fd[2]);
	}
	execute_bulit_in(l_parsing->l_simple_cmd, l_head_env, SINGLE_CMD);
	safe_dup2(temp_fd[0], 0);
	safe_dup2(temp_fd[1], 1);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_info_cmd		info_cmd;
	t_here_doc		*head_here_doc;
	t_env			*l_env_head;
	int				fd[3];

	info_cmd.l_here_doc = init_here_doc(l_parsing);
	if (info_cmd.l_here_doc == NULL)
		return ;
	l_env_head = l_env;
	head_here_doc = info_cmd.l_here_doc;
	init_valiable(fd, &info_cmd, l_parsing, &l_env);
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
		run_single_built_in(l_parsing, &info_cmd, fd, l_env_head);
	else
	{
		while (l_parsing)
		{
			if (l_parsing->next)
				safe_pipe(fd);
			info_cmd.pid = safe_fork();
			if (info_cmd.pid == 0)
				do_it_child(l_parsing, &info_cmd, fd, l_env_head);
			else
				do_it_parent(l_parsing->redir_iter, fd, &info_cmd);
			info_cmd.idx_curr_proc++;
			l_parsing = l_parsing->next;
		}
		wait_all_child(info_cmd.pid, info_cmd.num_proc);
	}
	ft_safe_free(info_cmd.args_execve.envp);
	// built in 일 때 here doc 고려 안 함
	free_all_here_doc(head_here_doc, 0);
}
