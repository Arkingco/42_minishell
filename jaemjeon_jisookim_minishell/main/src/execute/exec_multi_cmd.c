/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 01:09:53 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_multi(t_exec *exec, int i, t_fd *fd)
{
	t_cmd	*cmd;
	
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
	exec_executing(exec, i);

	exit(0);
}

void	init_pipe_before_exec(t_exec *exec, int i, t_fd *fd)
{
	//ft_close(fd->pipe_output_fd);
	// dprintf(2, "00 fd->pipe_input_fd_fd: %d\n", fd->pipe_input_fd);
	// dprintf(2, "00 fd->pipe_output_fd: %d\n", fd->pipe_output_fd);
	// dprintf(2, "00 fd->before_input_fd: %d\n", fd->before_input_fd);
	// dprintf(2, "----------------------\n");

	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);
	fd->before_input_fd = fd->pipe_output_fd;
	if (fd->pipe_input_fd != -1)
		ft_close(fd->pipe_input_fd);
	fd->pipe_input_fd = -1;
	fd->pipe_output_fd = -1;

	// dprintf(2, "01 fd->pipe_input_fd_fd: %d\n", fd->pipe_input_fd);
	// dprintf(2, "01 fd->pipe_output_fd: %d\n", fd->pipe_output_fd);
	// dprintf(2, "01 fd->before_input_fd: %d\n", fd->before_input_fd);
	// dprintf(2, "----------------------\n");
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
	return (exit_status);
}




// void	exec_multi(t_exec *exec, int i, t_fd *fd)
// {
// 	t_cmd	*cmd;
	
// 	cmd = get_cmd_for_index(exec, i);
// 	if (cmd && (cmd->redirect_input || cmd->redirect_output))
// 		exec_handle_redirection(exec, cmd);
// 	if (fd->before_input_fd != -1 && !cmd->redirect_input)
// 	{
// 		ft_dup2(fd->before_input_fd, 0);
// 		// dprintf(STDERR_FILENO, "ProcIdx[%d]: STDIN => %d\n", i, fd->before_input_fd);
// 	}
// 	// else
// 	// {
// 	// 	dprintf(STDERR_FILENO, "ProcIdx[%d]: STDIN =/=> cause (%d, %d)\n", i, fd->before_input_fd, !cmd->redirect_input);
// 	// }
// 	if (fd->pipe_output_fd != -1 && !cmd->redirect_output)
// 	{
// 		ft_dup2(fd->pipe_input_fd, 1);
// 		// dprintf(STDERR_FILENO, "ProcIdx[%d]: STDOUT => %d\n", i, fd->pipe_input_fd);
// 	}
// 	// else
// 	// {
// 	// 	dprintf(STDERR_FILENO, "ProcIdx[%d]: STDOUT =/=> cause (%d, %d)\n", i, fd->pipe_input_fd, !cmd->redirect_output);
// 	// }

// 	if (fd->pipe_input_fd != -1)
// 		ft_close(fd->pipe_input_fd);
// 	if (fd->pipe_output_fd != -1)
// 		ft_close(fd->pipe_output_fd);
// 	if (fd->before_input_fd != -1)
// 		ft_close(fd->before_input_fd);

// 	exec_executing(exec, i);

// 	exit(0);
// }
