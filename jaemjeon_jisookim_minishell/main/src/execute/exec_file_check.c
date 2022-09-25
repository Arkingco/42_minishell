/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:43:49 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:44:25 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


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
