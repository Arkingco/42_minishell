/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 21:57:14 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


pid_t	exec_multi_first(t_exec *exec, int i, pid_t *pid)
{
	int	stat;
	
	if (*pid == 0) //child process
	{	
		if (exec->cmds->redirect_input || exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		else if (!exec->cmds->redirect_output)
			ft_dup2(exec->pipe_fd[1], 1);
			
		ft_close(exec->pipe_fd[0]);
		ft_close(exec->pipe_fd[1]);
		
		if (exec->cmds->simple_cmd)
			exec_executing(exec, i, stat);
				
		exit(0);
	}
	dprintf(2, "first:) || exec->pipe_fd : [%d][%d][%d]\n", \
				exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);

	return (*pid);
}



pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid)
{
	int	stat;
	
	if (*pid == 0)
	{
		if (exec->cmds->redirect_input || exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		else if (!exec->cmds->redirect_input)
			ft_dup2(exec->pipe_fd[2], 0);
		else if (!exec->cmds->redirect_output)
			ft_dup2(exec->pipe_fd[1], 1);
			
		ft_close(exec->pipe_fd[0]);
		ft_close(exec->pipe_fd[2]);
		ft_close(exec->pipe_fd[1]);

		if (exec->cmds->simple_cmd)
			exec_executing(exec, i, stat);
			
		exit(0);
	}
	dprintf(2, "middle:) || exec->pipe_fd : [%d][%d][%d]\n", \
			exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);
	return (*pid);
}

pid_t	exec_multi_last(t_exec *exec, int i, pid_t *pid)
{
	int	stat;

	if (*pid == 0) //child process
	{		
		if (exec->cmds->redirect_input || exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		else if (!exec->cmds->redirect_output)
			ft_dup2(exec->pipe_fd[0], 0);

		ft_close(exec->pipe_fd[1]);
		ft_close(exec->pipe_fd[0]);	
		
		if (exec->cmds->simple_cmd)
			exec_executing(exec, i, stat);
			
		exit(0);
	}

	dprintf(2, "last:) || exec->pipe_fd : [%d][%d][%d]\n", \
			exec->pipe_fd[0], exec->pipe_fd[1], exec->pipe_fd[2]);
	
	ft_close(exec->pipe_fd[0]);
	ft_close(exec->pipe_fd[1]);
	if (exec->pipe_fd[2]) //process_cnt == 2 일때랑 아닐때랑 구분
		ft_close(exec->pipe_fd[2]);
	
	return (*pid); 
}

void	init_pipe_before_exec(t_exec *exec, int i)
{
	int	temp_fd;
	
	if ((exec->process_cnt != 2) && (i < exec->process_cnt - 2)) // 마지막 middle은 실행하면 안됨
	{
		temp_fd = 0;
		temp_fd = exec->pipe_fd[0];
		ft_close(exec->pipe_fd[1]);	
		exec->pipe_fd[1] = 0;
		if (exec->pipe_fd[2])
		{
			ft_close(exec->pipe_fd[2]);
			exec->pipe_fd[2] = 0;
		}
		exec->pipe_fd[0] = 0;
		exec->pipe_fd[2] = temp_fd;
	}
	return ;
}

int	multi_process_exceve(t_exec *exec)
{
	pid_t	*ret_pid;
	pid_t	pid;
	int		i;
	int		exit_status;

	ret_pid = ft_calloc(exec->process_cnt, sizeof(pid_t));
	i = 0;
	while (i < exec->process_cnt)
	{
		exec->temp_input_fd = exec_check_heredoc(exec, i);
		if (i != (exec->process_cnt - 1))
			ft_pipe(exec->pipe_fd);
		pid = ft_fork();
		if (i == 0) //first
			ret_pid[i] = exec_multi_first(exec, i, &pid);
		else if (i == (exec->process_cnt - 1))
			ret_pid[i] = exec_multi_last(exec, i, &pid); // last
		else
			ret_pid[i] = exec_multi_middle(exec, i, &pid); // middle
		init_pipe_before_exec(exec, i);
		i++;
	}
	exit_status = ft_wait(exec, ret_pid);
	return (exit_status);
}
