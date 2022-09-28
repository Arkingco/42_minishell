/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:52:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 12:40:56 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_and_get_infile_noexit(t_token *input)
{
	int	infile_fd;

	while (input)
	{
		infile_fd = open(input->string_value, O_RDONLY);
		if (infile_fd == -1)
		{
			if (errno == 13)
				process_errno(errno, input->string_value, OPEN_ERR);
			else
				process_errno(errno, input->string_value, OPEN_ERR);
		}
		if (input->next != NULL)
			close(infile_fd);
		input = input->next;
	}
	return (infile_fd);
}

int	check_and_get_outfile_noexit(t_token *output)
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
			process_errno(errno, output->string_value, OPEN_ERR);
		if (output->next != NULL)
			close(outfile_fd);
		output = output->next;
	}
	return (outfile_fd);
}
