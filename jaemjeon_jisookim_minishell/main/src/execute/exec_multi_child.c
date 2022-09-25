/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:24:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 23:31:54 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	handle_redi_multicmd_child(int *fd, t_cmd *my_cmd)
{
	if (my_cmd->redirect_input || my_cmd->redirect_output)
		handle_redirection_multi_cmd(my_cmd);
	if (fd[2] != OPEN_FAIL && my_cmd->redirect_input == NULL)
		ft_dup2(fd[2], 0);
	if (fd[0] != OPEN_FAIL && my_cmd->redirect_output == NULL)
		ft_dup2(fd[1], 1);
}

void	execute_multicmd_child(t_working_info *info, t_cmd *my_cmd, int *fd)
{
	int	cmd_type;

	info->cmd = my_cmd;
	handle_redi_multicmd_child(fd, my_cmd);
	close_useless_fds(fd);
	if (info->cmd->simple_cmd)
	{
		cmd_type = get_cmd_type(info->cmd);
		if (cmd_type == NOT_BUILT_IN)
			exec_executing(info);
		else
		{
			g_errno = process_built_in(info->cmd, info, cmd_type);
			exit(g_errno);
		}
	}
}
