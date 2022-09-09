/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/09 15:35:14 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

pid_t	ft_fork(void)
{
	pid_t	fork_return;
	
	fork_return = fork();
	if (fork_return == -1)
	{
		ft_putstr_fd("ERROR : pipe error during making pipe. \n", 2);
		exit(BAD_EXIT);
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
		ft_putstr_fd("ERROR : dup2() function error! \n", 2);
		exit(BAD_EXIT);
	}
	return (dup2_return); 
}

// if success : process id, WIFEXITED(wait_return) == TRUE
// if error : -1
pid_t	ft_wait(int *statloc, int i)
{
	int	wait_return;
	int	wait_error;
	
	wait_return = wait(&wait_return);
	
	if (wait_return == -1)
	{
		dprintf(2, "process number : %d\n", i);
		ft_putstr_fd("ERROR : wait() function error! \n", 2);
		exit(BAD_EXIT);
	}
	else if (WIFEXITED(wait_return))
	{
		ft_putstr_fd("GOOD! : wait function. \n", 1);
	}
	
	return (wait_return); 
}

// if success : ret == 0
// if error : ret == -1
int	*ft_pipe(int *pipe_fd)
{
	int	pipe_return;

	pipe_return = pipe(pipe_fd);
	if (pipe_return == -1)
	{
		ft_putstr_fd("ERROR : pipe error during making pipe. \n", 2);
		exit(BAD_EXIT);
	}
	if (pipe_return != 0)
	{
		ft_putstr_fd("ERROR : pipe error! Please put correct int array. \n", 2);
		exit(BAD_EXIT);
	}
	return (0);
}


void	exec_executing(t_exec *exec, int process_number, int stat)
{
	init_exec_struct(exec, process_number);
	if (exec->final_path == NULL)
		exec->final_path = exec->cmds->simple_cmd->string_value;
	stat = execve(exec->final_path, exec->final_cmd_str, exec->env_lst); //정상적으로 끝나면 여기서 종료.
	if (stat == -1)
	{
		ft_putstr_fd("ERROR : execve() function error. \n", 2);
		exit(1);
	}
}

int waiting_child(int argc, int last_pid_status)
{
	int status;
	int ret;

	while (argc - 1)
	{
		argc--;
		if (wait(&status) == last_pid_status)
			ret = status;
	}
	return (ret);
}
