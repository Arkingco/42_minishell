/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:20:36 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 17:01:33 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_open(const char *filename, int flags)
{
	int	open_return;
	open_return = open(filename, flags);
	if (open_return == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (open_return);
}

int	ft_close(int fd)
{
	int	close_return;
	close_return = close(fd);
	if (close_return != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (close_return);
}

void	close_all_fds(t_exec *exec, t_fd *fd)
{
	if (fd->pipe_input_fd != -1)
		ft_close(fd->pipe_input_fd);
	if (fd->pipe_output_fd != -1)
		ft_close(fd->pipe_output_fd);
	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);
	return ;
}
