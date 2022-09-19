/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:09 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 03:06:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_open(const char *filename, int flags, short mode)
{
	int	open_return;
	int	errno_tmp;

	if (flags & O_CREAT)
		open_return = open(filename, flags, mode);
	else
		open_return = open(filename, flags);
	if (open_return == -1)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	return (open_return);
}

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
		// printf("exit_status : %d\n", exit_status);
		i++;
	}
	return (exit_status);
}