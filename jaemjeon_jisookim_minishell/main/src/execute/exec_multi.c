/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:14:16 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 09:29:07 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

pid_t	*init_child_pids(t_working_info *info, int fd[])
{
	pid_t	*child_pids;

	ft_memset(fd, -1, sizeof(int) * 3);
	child_pids = ft_calloc(ft_cmdlst_size(info->cmd), sizeof(pid_t));
	if (child_pids == NULL)
		ft_error_exit(errno, "failed in malloc child pids");
	return (child_pids);
}

int	handle_wait_status(pid_t *child_pids, t_working_info *info)
{
	int	exit_status;

	exit_status = ft_wait_childs(child_pids, ft_cmdlst_size(info->cmd));
	if (WIFEXITED(exit_status))
		g_errno = WEXITSTATUS(exit_status);
	else
		g_errno = WCOREFLAG + WTERMSIG(exit_status);
	sigtermset(MINISHELL_NO_CHILD);
	free(child_pids);
	return (g_errno);
}

pid_t	process_multi_cmd_do_fork(t_working_info *info, t_cmd *cur_cmd, \
																	int fd[])
{
	pid_t	pid;

	if (cur_cmd->next != NULL)
		ft_pipe(fd);
	sigtermset(MINISHELL_HAS_CHILD);
	pid = ft_fork();
	if (pid == 0)
	{
		sigtermset(EXECUTE_CHILD);
		execute_multicmd_child(info, cur_cmd, fd);
	}
	return (pid);
}

pid_t	process_multi_cmd(t_working_info *info, int fd[])
{
	pid_t	*child_pids;
	int		index;
	t_cmd	*cur_cmd;

	child_pids = init_child_pids(info, fd);
	index = 0;
	cur_cmd = info->cmd;
	while (cur_cmd != NULL)
	{
		child_pids[index] = process_multi_cmd_do_fork(info, cur_cmd, fd);
		init_pipe_before_next_cmd(fd);
		index++;
		cur_cmd = cur_cmd->next;
	}
	close_useless_fds(fd);
	return (handle_wait_status(child_pids, info));
}
