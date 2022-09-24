/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:50:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 16:31:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_redirect_input(t_token *input_redirection)
{
	int		infile_fd;

	infile_fd = check_and_get_infile(input_redirection);
	if (infile_fd != OPEN_FAIL)
	{
		ft_dup2(infile_fd, 0);
		ft_close(infile_fd);
	}
}

void	handle_redirect_output(t_token *output_redirection)
{
	int		outfile_fd;
	int		type;

	outfile_fd = check_and_get_outfile(output_redirection);
	if (outfile_fd != OPEN_FAIL)
	{
		ft_dup2(outfile_fd, 1);
		ft_close(outfile_fd);
	}
}

void	handle_redirection_multi_cmd(t_cmd *cmd)
{
	if (cmd->redirect_input)
		handle_redirect_input(cmd->redirect_input);
	if (cmd->redirect_output)
		handle_redirect_output(cmd->redirect_output);
}

void	restore_redirect_fd(t_cmd *cmd, int *io_fd)
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

int	process_redirect(t_cmd *cmd, int *io_fd)
{
	if (cmd->redirect_input != NULL)
		io_fd[INPUT_REDI] = open_infile(cmd);
	if (cmd->redirect_output != NULL)
		io_fd[OUTPUT_REDI] = open_outfile(cmd);
	if (io_fd[INPUT_REDI] == OPEN_FAIL || io_fd[OUTPUT_REDI == OPEN_FAIL])
	{
		if (io_fd[INPUT_REDI] != OPEN_FAIL && io_fd[INPUT_REDI] != 0)
			close(io_fd[INPUT_REDI]);
		if (io_fd[OUTPUT_REDI] != OPEN_FAIL && io_fd[INPUT_REDI != 0])
			close(io_fd[OUTPUT_REDI]);
		return (OPEN_FAIL);
	}
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
	return (TRUE);
}
