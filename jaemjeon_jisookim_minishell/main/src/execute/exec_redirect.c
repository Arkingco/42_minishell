/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:50:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 13:01:25 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	restore_redirect_fds(t_cmd *cmd, int *io_fd)
{
	if (cmd->redirect_input != NULL && io_fd[STDIN_FILENO] != OPEN_FAIL)
	{
		dup2(io_fd[STDIN_FILENO], STDIN_FILENO);
		close(io_fd[STDIN_FILENO]);
	}
	if (cmd->redirect_output != NULL && io_fd[STDOUT_FILENO] != OPEN_FAIL)
	{
		dup2(io_fd[STDOUT_FILENO], STDOUT_FILENO);
		close(io_fd[STDOUT_FILENO]);
	}
}

void	dup2_io_fd(int *io_fd)
{
	if (io_fd[INPUT_REDI] != 0)
	{
		io_fd[STDIN_FILENO] = dup(STDIN_FILENO);
		dup2(io_fd[INPUT_REDI], STDIN_FILENO);
		close(io_fd[INPUT_REDI]);
	}
	if (io_fd[OUTPUT_REDI] != 0)
	{
		io_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
		dup2(io_fd[OUTPUT_REDI], STDOUT_FILENO);
		close(io_fd[OUTPUT_REDI]);
	}
}

int	process_redirect(t_cmd *cmd, int *io_fd)
{
	if (cmd->redirect_input != NULL)
		io_fd[INPUT_REDI] = open_infile(cmd);
	if (io_fd[INPUT_REDI] == OPEN_FAIL)
		return (OPEN_FAIL);
	if (cmd->redirect_output != NULL)
		io_fd[OUTPUT_REDI] = open_outfile(cmd);
	if (io_fd[OUTPUT_REDI] == OPEN_FAIL)
	{
		if (io_fd[INPUT_REDI] != OPEN_FAIL && io_fd[INPUT_REDI] != 0)
			close(io_fd[INPUT_REDI]);
		return (OPEN_FAIL);
	}
	dup2_io_fd(io_fd);
	return (TRUE);
}
