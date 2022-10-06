/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd_by_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:01:28 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:28:41 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "execution.h"

static void	init_input_fd(t_redir_chunk *l_input, int *fd,
				t_here_doc *l_here_doc)
{
	if (fd[2] != 0)
		safe_close(fd[2]);
	while (l_input)
	{
		if (l_input->type == T_INPUT_REDIR)
			fd[2] = safe_open(l_input->file_name, O_RDONLY);
		else
		{
			fd[2] = l_here_doc->read_end;
			l_here_doc = l_here_doc->next;
		}
		if (l_input->next)
			safe_close(fd[2]);
		l_input = l_input->next;
	}
}

static void	init_output_fd(t_redir_chunk *l_output, int *fd)
{
	if (fd[1] != 1)
		safe_close(fd[1]);
	while (l_output)
	{
		if (l_output->type == T_OUTPUT_REDIR)
			fd[1] = safe_open(l_output->file_name, \
						(O_TRUNC | O_WRONLY | O_CREAT));
		else
			fd[1] = safe_open(l_output->file_name, \
						(O_APPEND | O_WRONLY | O_CREAT));
		if (l_output->next)
			safe_close(fd[1]);
		l_output = l_output->next;
	}
}

void	init_fd_by_redirection(t_redir_iter *redir_iter, int *fd,
				t_here_doc *l_here_doc)
{
	if (redir_iter->l_input)
		init_input_fd(redir_iter->l_input, fd, l_here_doc);
	if (redir_iter->l_output)
		init_output_fd(redir_iter->l_output, fd);
}
