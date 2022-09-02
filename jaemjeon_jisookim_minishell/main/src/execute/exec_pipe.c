/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 18:48:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int before_execute(t_exec *exec)
{
	// make pipe
	//fork
	//execute in child process
	//wait_pid in parent process
	//wait_pid control
}



int	pipe_control(t_exec *exec, int pipe_type)
{
	int	pid;
	
	if (pipe_type == SINGLE_PIPE)
	{
		ft_pipe(exec->pipe_fd);
	}
	else if (pipe_type == ADDITIONAL_PIPE)
	{
		ft_pipe(exec->pipe_fd);
	}
	else
	{
		ft_putstr_fd("ERROR : ", 2);
		ft_putstr_fd("Invalid input during pipe_control() function. \n", 2);
		exit(BAD_EXIT);
	}
	return (0);
}