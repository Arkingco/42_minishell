/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_init_fd_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:14:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 17:04:11 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "fcntl.h"
#include "execution.h"
#include "libft.h"

static int	parent_is_exceed_max_fd(int fd)
{
	if (fd > 250)
	{
		safe_close(fd);
		ft_putendl_fd("Fd exceeds max!", 2);
		return (1);
	}
	return (0);
}

static int	init_input_fd(t_redir_chunk *l_input, int *fd,
				t_here_doc *l_here_doc)
{
	if (fd[2] != 0)
		safe_close(fd[2]);
	while (l_input)
	{
		if (l_input->type == T_INPUT_REDIR)
		{
			fd[2] = open(l_input->file_name, O_RDONLY);
			if (is_system_call_error(fd[2], l_input->file_name) \
					|| parent_is_exceed_max_fd(fd[2]))
				return (0);
		}
		else
		{
			fd[2] = l_here_doc->read_end;
			l_here_doc = l_here_doc->next;
		}
		if (l_input->next)
			safe_close(fd[2]);
		l_input = l_input->next;
	}
	return (1);
}

static int	init_output_fd(t_redir_chunk *l_output, int *fd)
{
	if (fd[1] != 1)
		safe_close(fd[1]);
	while (l_output)
	{
		if (l_output->type == T_OUTPUT_REDIR)
			fd[1] = open(l_output->file_name, (O_TRUNC | O_WRONLY | O_CREAT), \
						0666);
		else
			fd[1] = open(l_output->file_name, (O_APPEND | O_WRONLY | O_CREAT), \
						0666);
		if (is_system_call_error(fd[1], l_output->file_name) \
				|| parent_is_exceed_max_fd(fd[1]))
			return (0);
		if (l_output->next)
			safe_close(fd[1]);
		l_output = l_output->next;
	}
	return (1);
}

int	parent_init_fd_redir(t_redir_iter *redir_iter, int *fd,
			t_here_doc *l_here_doc)
{
	int	ret;

	ret = 1;
	if (redir_iter->l_input)
		ret = init_input_fd(redir_iter->l_input, fd, l_here_doc);
	if (ret == 0)
		return (0);
	if (redir_iter->l_output)
		ret = init_output_fd(redir_iter->l_output, fd);
	if (ret == 0)
		return (0);
	return (1);
}
