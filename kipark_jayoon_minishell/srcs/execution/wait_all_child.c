/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:21:25 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/04 21:56:56 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_status.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int	init_stat_loc_after_wait(pid_t last_fork_pid, size_t num_process)
{
	size_t	i;
	int		wait_pid;
	int		stat_loc;
	int		this_stat_loc;

	i = 0;
	while (i < num_process)
	{
		wait_pid = wait(&stat_loc);
		if (wait_pid != -1)
			i++;
		if (wait_pid == last_fork_pid)
			this_stat_loc = stat_loc;
	}
	return (this_stat_loc);
}

static void	init_exit_status(int status)
{
	int	return_code;
	int	signal_number;

	return_code = 0;
	signal_number = 0;
	if (WIFEXITED(status))
		return_code = WEXITSTATUS(status);
	else
	{
		return_code = 127;
		if (WIFSIGNALED(status))
			signal_number = WTERMSIG(status);
		else
		{
			if (WIFSTOPPED(status))
				signal_number = SIGSTOP;
			if (WIFCONTINUED(status))
				signal_number = SIGCONT;
		}			
	}
	g_exit_status = return_code + signal_number;
}

void	wait_all_child(pid_t last_fork_pid, size_t num_proc)
{
	int	stat_loc;

	stat_loc = init_stat_loc_after_wait(last_fork_pid, num_proc);
	init_exit_status(stat_loc);
}
