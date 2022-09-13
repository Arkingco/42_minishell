/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 12:14:33 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


pid_t	exec_multi_first(t_exec *exec, int i, pid_t *pid)
{
	int	stat;
	
	if (*pid == 0) //child process
	{	
		
		if (exec->cmds && exec->cmds->redirect_input || \
							exec->cmds && exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		if (!exec->cmds->redirect_output)
			ft_dup2(*exec->input_fd, 1);
	
		ft_close(*exec->input_fd);
		ft_close(*exec->output_fd);
		
		exec_executing(exec, i, stat);
				
		exit(0);
	}
	return (*pid);
}

pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid)
{
	int	stat;
	
	if (*pid == 0)
	{
		if (exec->cmds && exec->cmds->redirect_input || \
							exec->cmds && exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		if (!exec->cmds->redirect_input)
			ft_dup2(*exec->output_fd, 0);
		if (!exec->cmds->redirect_output)
			ft_dup2(*exec->input_fd, 1);
		
		ft_close(*exec->input_fd);
		ft_close(*exec->output_fd);

		exec_executing(exec, i, stat);
			
		exit(0);
	}
	return (*pid);
}

pid_t	exec_multi_last(t_exec *exec, int i, pid_t *pid)
{
	int	stat;

	if (*pid == 0) //child process
	{	
		if (exec->cmds && exec->cmds->redirect_input || \
							exec->cmds && exec->cmds->redirect_output)
			exec_handle_redirection(exec, i);
		if (!exec->cmds->redirect_input)
			ft_dup2(*exec->output_fd, 0);

		ft_close(*exec->input_fd);
		ft_close(*exec->output_fd);
		
		exec_executing(exec, i, stat);
			
		exit(0);
	}
	return (*pid); 
}

// 부모 프로세스에서 정리
void	init_pipe_before_exec(t_exec *exec, int i)
{
	dprintf(2, "infile_fd : %d\n", *exec->input_fd);
	dprintf(2, "outfile_fd : %d\n", *exec->output_fd);
	dprintf(2, "before_input_fd : %d\n", *exec->before_input_fd);

	if ((exec->process_cnt != 2) && (i < exec->process_cnt - 2)) // 마지막 middle은 실행하면 안됨
	{
		if (*exec->output_fd != -1)
		{
			if (*exec->before_input_fd != -1)
				ft_close(*exec->before_input_fd);
			*exec->before_input_fd = *exec->output_fd;
			*exec->output_fd = -1;
		}
		if (*exec->input_fd != -1)
		{
			ft_close(*exec->input_fd);
			*exec->input_fd = -1;
		}
	}
	if (i < exec->process_cnt - 1)
	{
		ft_close(*exec->input_fd);
		ft_close(*exec->output_fd);
		if (*exec->before_input_fd != -1)
			ft_close(*exec->output_fd);
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
		if (i != (exec->process_cnt - 1))
			ft_pipe(exec->pipe_fd);
		*exec->input_fd = exec->pipe_fd[1];
		*exec->output_fd = exec->pipe_fd[0];
		pid = ft_fork();
		if (i == 0) 
			ret_pid[i] = exec_multi_first(exec, i, &pid);
		else if (i == (exec->process_cnt - 1))
			ret_pid[i] = exec_multi_last(exec, i, &pid);
		else
			ret_pid[i] = exec_multi_middle(exec, i, &pid);
		init_pipe_before_exec(exec, i);
		i++;
	}
	exit_status = ft_wait(exec, ret_pid);
	return (exit_status);
}
