/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:21:25 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/26 16:22:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>

// global variable
int	g_exit_status;

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
		if (wait_pid == last_fork_pid)
			this_stat_loc = stat_loc;
		i++;
	}
	return (this_stat_loc);
}

static void	init_exit_code(int status)
{
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else
	{
		if (WIFSIGNALED(status))
			WTERMSIG(status);
		else
		{
			if (WIFSTOPPED(status))
			;
				//SIGSTOP 17
			if (WIFCONTINUED(status))
			;
				//SIGCONT 19
		}			
	}
}

void	wait_all_child(pid_t last_fork_pid, size_t num_process)
{
	int	stat_loc;

	stat_loc = init_stat_loc_after_wait(last_fork_pid, num_process);
	init_exit_code(stat_loc);
}
