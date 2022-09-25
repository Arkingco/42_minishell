/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:00:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 18:01:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;


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
	int	outfile_fd;

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
