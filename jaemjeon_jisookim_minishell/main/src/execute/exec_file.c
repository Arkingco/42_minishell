/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:52:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 10:55:27 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


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
		perror("open error");
		return (OPEN_FAIL);
	}
	while (redircet_token->next != NULL)
	{
		redircet_token = redircet_token->next;
		close(infile_fd);
		infile_fd = open(redircet_token->string_value, O_RDONLY);
		if (infile_fd == OPEN_FAIL)
		{
			perror("open error");
			return (OPEN_FAIL);
		}
	}
	return (infile_fd);
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
		perror("open error");
	while (redircet_token->next != NULL)
	{
		redircet_token = redircet_token->next;
		close(outfile_fd);
		outfile_fd = open(redircet_token->string_value, open_option, 0644);
		if (outfile_fd == OPEN_FAIL)
			perror("open error");
	}
	return (outfile_fd);
}


int	check_and_get_infile(t_token *input)
{
	int	infile_fd;

	while (input)
	{
		infile_fd = open(input->string_value, O_RDONLY);
		if (infile_fd == -1)
		{
			ft_putstr_fd(input->string_value, 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		if (input->next != NULL)
			close(infile_fd);
		input = input->next;
	}
	return (infile_fd);
}


int	check_and_get_outfile(t_token *output)
{
	int	outfile_fd;

	while (output)
	{
		if (output->type & WRITE)
			outfile_fd = open(output->string_value, \
										O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (output->type & WRITE_APPEND)
			outfile_fd = open(output->string_value, \
										O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (outfile_fd == -1)
		{
			ft_putstr_fd(output->string_value, 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		if (output->next != NULL)
			close(outfile_fd);
		output = output->next;
	}
	return (outfile_fd);
}
