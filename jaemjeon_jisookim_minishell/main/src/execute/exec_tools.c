/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 01:43:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

pid_t	ft_fork(void)
{
	pid_t	fork_return;
	
	fork_return = fork();
	if (fork_return == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
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
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (dup2_return); 
}

// if success : process id, WIFEXITED(wait_return) == TRUE
// if error : -1
pid_t	ft_wait(int count, pid_t *child_pids)
{
	int	i;
	int exit_status;

	i = 0;
	while (i < count)
	{
		waitpid(child_pids[i], &exit_status, 0);
		// printf("exit_status : %d\n", exit_status);
		i++;
	}
	return (exit_status);
}

// if success : ret == 0
// if error : ret == -1
int	ft_pipe(int *pipe_fd)
{
	int	pipe_return;

	pipe_return = pipe(pipe_fd);
	if (pipe_return != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (pipe_return);
}


void	exec_executing(t_exec *exec, int process_number)
{
	int	stat;

	
	init_exec_struct(exec, process_number);
	stat = execve(exec->final_path, exec->final_cmd_str, exec->env_lst); //정상적으로 끝나면 여기서 종료.
	if (!exec->final_cmd_str[0])
		exit(0);
	if (stat == -1)
	{
		
	}
}



// dprintf(2, "exec->final_path : %s\n", exec->final_path);
// 	dprintf(2, "exec->final_cmd_str[0] : %s\n", exec->final_cmd_str[0]);
// 	dprintf(2, "exec->final_cmd_str[1] : %s\n", exec->final_cmd_str[1]);
// 	dprintf(2, "exec->env_lst[0] : %s\n", exec->env_lst[0]);
// 	dprintf(2, "exec->env_lst[1] : %s\n", exec->env_lst[1]);
