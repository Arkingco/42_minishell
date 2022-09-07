/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:39 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_double_free(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

pid_t	ft_fork(void)
{
	pid_t	fork_return;
	
	fork_return = fork();
	if (fork_return == -1)
	{
		ft_putstr_fd("ERROR : pipe error during making pipe. \n", 2);
		exit(BAD_EXIT);
	}
	return (fork_return);
}

// change fd, fd2 points where fd1 points.
// if function worked well, fd2 will return.
int	ft_dup2(int fd1, int fd2)
{
	int	dup2_return;
	
	dup2_return = dup2(fd1, fd2);
	if (dup2_return == -1)
	{
		ft_putstr_fd("ERROR : dup2() function error! \n", 2);
		exit(BAD_EXIT);
	}
	return (dup2_return); 
}

// if success : process id, WIFEXITED(wait_return) == TRUE
// if error : -1, WIFSIGNALED(wait_return) == TRUE
pid_t	ft_wait(int *statloc)
{
	int	wait_return;
	int	wait_error;
	
	wait_return = wait(&wait_return);
	if (wait_return == -1)
	{
		ft_putstr_fd("ERROR : wait() function error! \n", 2);
		exit(BAD_EXIT);
	}
	if (WIFSIGNALED(wait_return) || !WIFEXITED(wait_return))
	{
		wait_error = WTERMSIG(statloc);
		ft_putstr_fd("ERROR : child process error!", 2);
		write(2, "\n", 1);
		exit(BAD_EXIT);
	}
	return (wait_return); 
}

// if success : ret == 0
// if error : ret == -1
int	*ft_pipe(int *pipe_fd)
{
	int	pipe_return;

	pipe_return = pipe(pipe_fd);
	if (pipe_return == -1)
	{
		ft_putstr_fd("ERROR : pipe error during making pipe. \n", 2);
		exit(BAD_EXIT);
	}
	if (pipe_return != 0)
	{
		ft_putstr_fd("ERROR : pipe error! Please put correct int array. \n", 2);
		exit(BAD_EXIT);
	}
	return (0);
}

int	ft_exceve(const char *filename, char *const argv[], char *const envp[])
{
	int	execve_return;
	execve_return = execve(filename, argv, envp);
	if (execve_return == -1)
	{
		ft_putstr_fd("ERROR : execve() function error. \n", 2);
		exit(BAD_EXIT);
	}
	return (execve_return);
}
