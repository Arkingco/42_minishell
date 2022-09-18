/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 11:17:42 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_multi(t_exec *exec, int i, t_fd *fd)
{
	t_cmd	*cmd;
	
	set_sigtermset(IN_CHILD);
	cmd = get_cmd_for_index(exec, i);
	if (cmd && (cmd->redirect_input || cmd->redirect_output))
		exec_handle_redirection(exec, cmd, i);
	if (fd->before_input_fd != -1 && !cmd->redirect_input)
	{
		ft_dup2(fd->before_input_fd, 0);
	}
	if (fd->pipe_output_fd != -1 && !cmd->redirect_output)
	{
		ft_dup2(fd->pipe_input_fd, 1);
	}
	close_all_fds(exec, fd);
	if (exec->cmds->simple_cmd && check_built_in(exec))
		exec_go_built_in(exec);
	exec_executing(exec, i);
	exit(0);
}

void	init_pipe_before_exec(t_exec *exec, int i, t_fd *fd)
{
	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);
	fd->before_input_fd = fd->pipe_output_fd;
	if (fd->pipe_input_fd != -1)
		ft_close(fd->pipe_input_fd);
	fd->pipe_input_fd = -1;
	fd->pipe_output_fd = -1;
	return ;
}

int	multi_process_exceve(t_exec *exec, t_fd *fd)
{
	pid_t	*ret_pid;
	pid_t	pid;
	int		i;
	int		exit_status;

	ret_pid = ft_calloc(exec->process_cnt, sizeof(pid_t));
	i = 0;
	set_sigtermset(IN_MINISHELL_HAS_CHILD);
	while (i < exec->process_cnt)
	{
		if (i < exec->process_cnt - 1)
			ft_pipe(exec->pipe_fd);
		fd->pipe_input_fd = exec->pipe_fd[1];
		fd->pipe_output_fd = exec->pipe_fd[0];
		exec->pipe_fd[0] = -1;
		exec->pipe_fd[1] = -1;
		pid = ft_fork();
		if (pid == 0)
			exec_multi(exec, i, fd);
		ret_pid[i] = pid;
		init_pipe_before_exec(exec, i, fd);
		i++;
	}
	close_all_fds(exec, fd);
	exit_status = ft_wait(exec->process_cnt, ret_pid);
	set_sigtermset(IN_MINISHELL_NO_CHILD);
	return (exit_status);
}
