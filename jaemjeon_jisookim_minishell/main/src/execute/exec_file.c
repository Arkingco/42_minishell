/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:52:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 22:49:06 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_infile_check_next(t_token *redircet_token, int *infile_fd)
{
	close(*infile_fd);
	*infile_fd = open(redircet_token->string_value, O_RDONLY);
	if (*infile_fd == OPEN_FAIL)
	{
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
		return (OPEN_FAIL);
	}
	return (0);
}

int	open_infile(t_cmd *cmd)
{
	t_token	*redircet_token;
	int		infile_fd;

	redircet_token = cmd->redirect_input;
	if (redircet_token == NULL)
		return (STDIN_FILENO);
	infile_fd = open(redircet_token->string_value, O_RDONLY);
	if (infile_fd == OPEN_FAIL)
	{
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
		return (OPEN_FAIL);
	}
	redircet_token = redircet_token->next;
	while (redircet_token != NULL)
	{
		if (open_infile_check_next(redircet_token, &infile_fd) == OPEN_FAIL)
			return (OPEN_FAIL);
		redircet_token = redircet_token->next;
	}
	return (infile_fd);
}

int	open_outfile_check_next(t_token *redircet_token, int *outfile_fd, \
															int open_option)
{
	close(*outfile_fd);
	*outfile_fd = open(redircet_token->string_value, open_option, 0644);
	if (*outfile_fd == OPEN_FAIL)
	{
		process_errno(errno, redircet_token->string_value, OPEN_ERR);
		return (OPEN_FAIL);
	}
	return (0);
}

int	open_outfile(t_cmd *cmd)
{
	t_token	*redircet_token;
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
	redircet_token = redircet_token->next;
	while (redircet_token != NULL)
	{
		if (open_outfile_check_next(redircet_token, &outfile_fd, open_option) \
																== OPEN_FAIL)
			return (OPEN_FAIL);
		redircet_token = redircet_token->next;
	}
	return (outfile_fd);
}
