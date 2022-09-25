/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:52:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:44:21 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_infile_check_next(t_token *redircet_token, int infile_fd)
{
	redircet_token = redircet_token->next;
	close(infile_fd);
	infile_fd = open(redircet_token->string_value, O_RDONLY);
	if (infile_fd == OPEN_FAIL)
	{
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
		return (OPEN_FAIL);
	}
	return (0);
}

int	open_infile(t_cmd *cmd)
{
	t_token *redircet_token;
	int	infile_fd;

	redircet_token = cmd->redirect_input;
	if (redircet_token == NULL)
		return (STDIN_FILENO);
	infile_fd = open(redircet_token->string_value, O_RDONLY);
	if (infile_fd == OPEN_FAIL)
	{
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
		return (OPEN_FAIL);
	}
	while (redircet_token->next != NULL)
	{
		if (open_infile_check_next(redircet_token, infile_fd))
			return (OPEN_FAIL);
	}
	return (infile_fd);
}

void	open_outfile_check_next(t_token *redircet_token, int outfile_fd, \
															int open_option)
{
	redircet_token = redircet_token->next;
	close(outfile_fd);
	outfile_fd = open(redircet_token->string_value, open_option, 0644);
	if (outfile_fd == OPEN_FAIL)
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
}

int	open_outfile(t_cmd *cmd)
{
	t_token *redircet_token;
	int		open_option;
	int		outfile_fd;

	redircet_token = cmd->redirect_output;
	if (redircet_token == NULL)
		return (STDOUT_FILENO);
	if (redircet_token->type & WRITE_APPEND)
		open_option = O_WRONLY | O_CREAT | O_APPEND;
	else
		open_option = O_WRONLY | O_CREAT;
	outfile_fd = open(redircet_token->string_value, open_option, 0644);
	if (outfile_fd == OPEN_FAIL)
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
	while (redircet_token->next != NULL)
		open_outfile_check_next(redircet_token, outfile_fd, open_option);
	return (outfile_fd);
}
