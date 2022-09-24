/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 11:03:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	process_single_cmd(t_working_info *info)
{
	int	cmd_type;
	int	io_fd[4];

	if (info->cmd->simple_cmd)
	{
		process_redirect(info->cmd, io_fd);
		cmd_type = get_cmd_type(info->cmd);
		if (cmd_type == NOT_BUILT_IN)
			process_not_built_in(info);
		else
			process_built_in(info->cmd, info, cmd_type);
	}
	restore_redirect_fd(info->cmd, io_fd);
}


void	execute_multicmd_child(t_working_info *info, t_cmd *my_cmd, int *fd)
{
	info->cmd = my_cmd;
	if (my_cmd->redirect_input || my_cmd->redirect_output)
		handle_redirection_multi_cmd(my_cmd);
	if (fd[BEFORE_INPUT_FD] != -1 && my_cmd->redirect_input == NULL)
	{
		ft_dup2(fd[BEFORE_INPUT_FD], 0);
	}
	if (fd[MULTI_PIPE_OUTPUT] != -1 && my_cmd->redirect_output == NULL)
	{
		ft_dup2(fd[MULTI_PIPE_INPUT], 1);
	}
	close_useless_fds(fd);
	exec_executing(info);
	exit(0);
}

pid_t	process_multi_cmd(t_working_info *info)
{
	pid_t	pid;
	int		fd[3];
	pid_t	*child_pids;
	int		index;
	t_cmd	*cur_cmd;

	ft_memset(fd, -1, sizeof(int) * 3);
	child_pids = ft_calloc(ft_cmdlst_size(info->cmd), sizeof(pid_t));
	// ft_calloc 널가드 -> 널가드를 포함하여 에러출력하고 종료하는 함수가 필요
	cur_cmd = info->cmd;
	index = 0;
	while (cur_cmd != NULL)
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
		child_pids[index] = pid;
		init_pipe_before_next_cmd(cur_cmd, fd);
		index++;
		cur_cmd = cur_cmd->next;
	}
	close_useless_fds(fd);
	return (ft_wait_childs(child_pids, ft_cmdlst_size(info->cmd)));
}

void	execute(t_working_info *info)
{
	int	cmd_count;
	int	status;

	cmd_count = ft_cmdlst_size(info->cmd);
	if (has_heredoc(info))
		status = heredoc(info);
	else
		status = TRUE;
	if (status == TRUE)
	{
		if (cmd_count == 1)
			process_single_cmd(info);
		else
			process_multi_cmd(info);
	}
}
