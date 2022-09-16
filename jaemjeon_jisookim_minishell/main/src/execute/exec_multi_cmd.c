/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 14:35:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_multi(t_exec *exec, int i, t_fd *fd)
{
	t_cmd	*cmd;
	
	cmd = get_cmd_for_index(exec, i);
	if (cmd && (cmd->redirect_input || cmd->redirect_output))
		exec_handle_redirection(exec, cmd);
	if (fd->before_input_fd != -1 && !cmd->redirect_input)
	{
		ft_dup2(fd->before_input_fd, 0);
	}
	if (fd->output_fd != -1 && !cmd->redirect_output)
	{
		ft_dup2(fd->input_fd, 1);
	}

	if (fd->input_fd != -1)
		ft_close(fd->input_fd);
	if (fd->output_fd != -1)
		ft_close(fd->output_fd);
	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);

	exec_executing(exec, i);

	exit(0);
}

// 부모 프로세스에서 정리
void	init_pipe_before_exec(t_exec *exec, int i, t_fd *fd)
{
	//ft_close(fd->output_fd);
	// dprintf(2, "00 fd->input_fd_fd: %d\n", fd->input_fd);
	// dprintf(2, "00 fd->output_fd: %d\n", fd->output_fd);
	// dprintf(2, "00 fd->before_input_fd: %d\n", fd->before_input_fd);
	// dprintf(2, "----------------------\n");

	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);
	fd->before_input_fd = fd->output_fd;
	if (fd->input_fd != -1)
		ft_close(fd->input_fd);
	fd->input_fd = -1;
	fd->output_fd = -1;

	// dprintf(2, "01 fd->input_fd_fd: %d\n", fd->input_fd);
	// dprintf(2, "01 fd->output_fd: %d\n", fd->output_fd);
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
		fd->input_fd = exec->pipe_fd[1];
		fd->output_fd = exec->pipe_fd[0];
		exec->pipe_fd[0] = -1;
		exec->pipe_fd[1] = -1;
		// dprintf(2, "+++ fd->input_fd_fd: %d\n", fd->input_fd);
		// dprintf(2, "+++ fd->output_fd: %d\n", fd->output_fd);
		// dprintf(2, "+++ fd->before_input_fd: %d\n", fd->before_input_fd);
		// dprintf(2, "----------------------\n");
		pid = ft_fork();
		if (pid == 0)
			exec_multi(exec, i, fd);
		ret_pid[i] = pid;
		init_pipe_before_exec(exec, i, fd);
		i++;
	}
	if (fd->input_fd != -1)
		ft_close(fd->input_fd);
	if (fd->output_fd != -1)
		ft_close(fd->output_fd);
	if (fd->before_input_fd != -1)
		ft_close(fd->before_input_fd);
	exit_status = ft_wait(exec, ret_pid);
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
// 	if (fd->output_fd != -1 && !cmd->redirect_output)
// 	{
// 		ft_dup2(fd->input_fd, 1);
// 		// dprintf(STDERR_FILENO, "ProcIdx[%d]: STDOUT => %d\n", i, fd->input_fd);
// 	}
// 	// else
// 	// {
// 	// 	dprintf(STDERR_FILENO, "ProcIdx[%d]: STDOUT =/=> cause (%d, %d)\n", i, fd->input_fd, !cmd->redirect_output);
// 	// }

// 	if (fd->input_fd != -1)
// 		ft_close(fd->input_fd);
// 	if (fd->output_fd != -1)
// 		ft_close(fd->output_fd);
// 	if (fd->before_input_fd != -1)
// 		ft_close(fd->before_input_fd);

// 	exec_executing(exec, i);

// 	exit(0);
// }
