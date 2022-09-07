/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 22:42:02 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


pid_t	exec_multi_first(t_exec *exec, pid_t *pid)
{
	int		stat;

	if (pid == 0) //child process
	{
		dprintf(2, " +++++++++ this is [%d](pid) multi first!  +++++++++ \n", (int)pid);
		dprintf("exec->pipe_fd[0] : %d\n", (int)exec->pipe_fd[0]);
		dprintf("exec->pipe_fd[1] : %d\n", (int)exec->pipe_fd[1]);
		ft_close(exec->pipe_fd[0]);
		// redirection check
		ft_dup2(exec->pipe_fd[1], 1);
		ft_close(exec->pipe_fd[1]);	

		exec_executing(exec, 0, stat, pid);
	}
	return (ft_wait(&stat)); // todo : return exit stat
}

pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid)
{
	dprintf(2, "no middle!\n");
	// pid_t	pid;
	// int		stat;
	// ft_pipe(exec->pipe_fd); //pipe

	// pid = ft_fork(); //fork -> get pid
	// if (pid == 0) //child process
	// {
	// 	ft_close(exec->pipe_fd[0]);
	// 	// redirection check
	// 	ft_dup2(exec->pipe_fd[1], 1);
	// 	close (exec->pipe_fd[1]);	
	// }
	// pid = ft_fork();
	// if (pid == 0)
	// {
	// 	exec_executing(exec, exec->process_cnt, stat, pid);
	// }
	// return (ft_wait(&stat)); // todo : return exit stat
	return (0);
}

pid_t	exec_multi_last(t_exec *exec, pid_t *pid)
{
	int		stat;


	if (pid == 0 && exec->process_cnt == 2) //child process
	{
		dprintf(2, " +++++++++ this is [%d](pid) multi last!  +++++++++ \n", (int)pid);
		dprintf(2, "+++ process cnt is 2! +++ \n");
		ft_close(exec->pipe_fd[1]);
		ft_dup2(exec->pipe_fd[0], 0);
		ft_close(exec->pipe_fd[0]);	
		// redirection check
		exec_executing(exec, (exec->process_cnt - 1), stat, pid);
	}
	else
	{
		;
	}
	
	return (ft_wait(&stat)); // todo : return exit stat
}


// ================================================================
// ================================================================


int	multi_process_exceve(t_exec *exec, int i, pid_t *pid)
{
	pid_t	ret_pid;

	if (i == 0) //first
		ret_pid = exec_multi_first(exec, pid);
	else if (i == (exec->process_cnt - 1)) // last
		ret_pid = exec_multi_last(exec, pid);
	else // middle
		ret_pid = exec_multi_middle(exec, i, pid);


	return (ret_pid);
}


// ================================================================

int	exec_multi_child_process(t_exec *exec)
{
	pid_t	fork_ret;
	pid_t	ret_pid;
	pid_t	pid;
	int		stat;
	int		i;

	i = 0;
	while (i < exec->process_cnt)
	{
		if (i != (exec->process_cnt - 1))
			ft_pipe(exec->pipe_fd); //pipe
		// pipe control
		pid = ft_fork(); //fork -> get pid
		ret_pid = multi_process_exceve(exec, i, pid);
		i++;
	}
	ft_close(exec->pipe_fd[0]);
	ft_close(exec->pipe_fd[1]);
	// ft_close(exec->pipe_fd[2]);

	// printf("\n\n========= DEBUG PIPE ============\n");
	// printf("pipe[0] : %d\n", exec->pipe_fd[0]);
	// printf("pipe[0] : %d\n", exec->pipe_fd[1]);
	// printf("pipe[0] : %d\n", exec->pipe_fd[2]);
	// printf("\n========= DEBUG PIPE ============\n\n");

	if (ret_pid == -1)
		ft_putstr_fd("ERROR! : error during getting ret_pid.\n", 2);
	return (ret_pid); // returning pid, pid fail(-1)
}
