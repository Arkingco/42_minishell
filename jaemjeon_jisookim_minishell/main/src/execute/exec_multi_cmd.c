/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/08 14:47:34 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


pid_t	exec_multi_first(t_exec *exec, int i, pid_t *pid)
{
	int	stat;

	dprintf(2, "this is my pid: %d \n", *pid);
	if (pid == 0) //child process
	{
		dprintf(2, "this is child! \n");
		ft_close(exec->pipe_fd[0]);
		// redirection check
		ft_dup2(exec->pipe_fd[1], 1);
		ft_close(exec->pipe_fd[1]);	

		exec_executing(exec, i, stat);
	}
	
	return ((pid_t)stat); // todo : return exit stat
}

pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid)
{
	int	stat;
	
	dprintf(2, "this is my pid: %d \n", *pid);
	if (pid == 0)
	{
		dprintf(2, "this is child! \n");
		ft_dup2(exec->pipe_fd[2], 0);
		ft_close(exec->pipe_fd[2]);

		ft_dup2(exec->pipe_fd[1], 1);
		close(exec->pipe_fd[1]);
		exec_executing(exec, i, stat);
	}

	return ((pid_t)stat); // todo : return exit stat
}

pid_t	exec_multi_last(t_exec *exec, int i, pid_t *pid)
{
	int	stat;

	dprintf(2, "this is my pid: %d \n", *pid);
	if (pid == 0) //child process
	{
		dprintf(2, "this is child! \n");
		ft_dup2(exec->pipe_fd[0], 0);
		ft_close(exec->pipe_fd[0]);	
		// redirection check
		exec_executing(exec, i, stat);
	}

	return ((pid_t)stat); // todo : return exit stat
}


// ================================================================
// ================================================================

//middle cmd (multi) tools
void	init_pipe_before_exec(t_exec *exec, int i)
{
	int	temp_fd;

	temp_fd = 0;

	if (i != (exec->process_cnt - 1))
	{
		ft_close(exec->pipe_fd[1]);	
		exec->pipe_fd[1] = 0;
	}
	temp_fd = exec->pipe_fd[0];
	exec->pipe_fd[0] = 0;
	exec->pipe_fd[2] = temp_fd;
	
	dprintf(2, "exec->pipe_fd : [%d][%d][%d]\n", \
					exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);

	return ;
}

// todo : need to work on pipe
int	multi_process_exceve(t_exec *exec)
{
	pid_t	ret_pid;
	pid_t	pid;
	int		i;

	i = 0;
	while (i < exec->process_cnt)
	{
		if (i != (exec->process_cnt - 1))
			ft_pipe(exec->pipe_fd);
		pid = ft_fork();
		if (i == 0) //first
		{
			dprintf(2, "\n\n<<<FIRST[%d]>>>\n", i);
			dprintf(2, "** exec->pipe_fd : [%d][%d][%d]\n", exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);
			ret_pid = exec_multi_first(exec, i, &pid);
		}
		else if (i == (exec->process_cnt - 1))
		{ 
			dprintf(2, "\n\n<<<LAST[%d]>>>\n", i);
			dprintf(2, "** exec->pipe_fd : [%d][%d][%d]\n", exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);
			ret_pid = exec_multi_last(exec, i, &pid); // last
			// todo : pipe handling, close pipe
		}
		else
		{
			dprintf(2, "\n\n<<<MIDDLE[%d]>>>\n", i);
			ret_pid = exec_multi_middle(exec, i, &pid); // middle
		}
		init_pipe_before_exec(exec, i);
		i++;
	}
	
	return (ret_pid);
}


// ================================================================

