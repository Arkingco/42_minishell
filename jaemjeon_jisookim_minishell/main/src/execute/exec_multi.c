/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:14:16 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 20:24:46 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

pid_t	*init_exec_multi(t_working_info *info, int fd[], \
											pid_t *child_pids, t_cmd *cur_cmd)
{
	ft_memset(fd, -1, sizeof(int) * 3);
	child_pids = ft_calloc(ft_cmdlst_size(info->cmd), sizeof(pid_t));
	if (child_pids == NULL)
	{
		child_pids = 0;
		ft_error_exit(errno, "failed in malloc child pids");
	}
	cur_cmd = info->cmd;
}

int	handle_wait_status(pid_t *child_pids, t_working_info *info, pid_t pid)
{
	int	exit_status;

	exit_status = 0;
	exit_status = ft_wait_childs(child_pids, ft_cmdlst_size(info->cmd));
	if (WIFEXITED(pid))
		g_errno = WEXITSTATUS(pid);
	else
		g_errno = WCOREFLAG + WTERMSIG(pid);
	sigtermset(MINISHELL_NO_CHILD);
	return (exit_status);
}

void	process_multi_cmd_do_fork(t_working_info *info, t_cmd *cur_cmd, \
														int fd[], pid_t pid)
{
	if (cur_cmd->next != NULL)
		ft_pipe(fd);
	sigtermset(MINISHELL_HAS_CHILD);
	pid = ft_fork();
	if (pid == 0)
	{
		sigtermset(EXECUTE_CHILD);
		execute_multicmd_child(info, cur_cmd, fd);
	}
}

pid_t	process_multi_cmd(t_working_info *info, int fd[])
{
	pid_t	pid;
	pid_t	*child_pids;
	int		index;
	t_cmd	*cur_cmd;

	init_exec_multi(info, fd, child_pids, cur_cmd);
	child_pids = init_child_pids(info);
	index = 0;
	while (cur_cmd != NULL)
	{
		process_multi_cmd_do_fork(info, cur_cmd, fd, pid);
		child_pids[index] = pid;
		init_pipe_before_next_cmd(cur_cmd, fd);
		index++;
		cur_cmd = cur_cmd->next;
	}
	close_useless_fds(fd);
	return (handle_wait_status(child_pids, info, pid));
}
