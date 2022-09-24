/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ft_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:09 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 13:29:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_close(int fd)
{
	int	close_return;
	int	errno_tmp;

	close_return = close(fd);
	if (close_return != 0)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	return (close_return);
}

pid_t	ft_fork(void)
{
	pid_t	fork_return;
	
	fork_return = fork();
	if (fork_return == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (fork_return);
}

pid_t	ft_wait(int count, pid_t *child_pids)
{
	int	i;
	int exit_status;

	i = 0;
	while (i < count)
	{
		waitpid(child_pids[i], &exit_status, 0);
		i++;
	}
	return (exit_status);
}

int	ft_dup2(int fd1, int fd2)
{
	int	dup2_return;
	
	dup2_return = dup2(fd1, fd2);
	if (dup2_return == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (dup2_return); 
}

int	ft_pipe(int *pipe_fd)
{
	int	pipe_return;

	pipe_return = pipe(pipe_fd);
	if (pipe_return != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (pipe_return);
}
