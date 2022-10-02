/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/27 13:52:43 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	process_single_cmd(t_working_info *info)
{
	int	cmd_type;
	int	io_fd[4];

	ft_memset(io_fd, 0, sizeof(int) * 4);
	if (process_redirect(info->cmd, io_fd) != FAIL)
	{
		if (info->cmd->simple_cmd)
		{
			cmd_type = get_cmd_type(info->cmd);
			if (cmd_type == NOT_BUILT_IN)
				process_not_built_in(info);
			else
				process_built_in(info->cmd, info, cmd_type);
		}
		restore_redirect_fds(info->cmd, io_fd);
	}
}

void	execute(t_working_info *info)
{
	int	cmd_count;
	int	fd[3];
	int	status;

	cmd_count = ft_cmdlst_size(info->cmd);
	if (has_heredoc(info))
		status = heredoc(info);
	else
		status = 0;
	if (status == 0)
	{
		if (cmd_count == 1)
			process_single_cmd(info);
		else
			process_multi_cmd(info, fd);
	}
	unlink_hdoc_tmpfiles(info->cmd);
}
