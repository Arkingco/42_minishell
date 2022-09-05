/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 10:31:39 by jisookim         ###   ########.fr       */
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
	return (0);
}



int	exec_pipe_control(t_exec *exec)
{
	int	pid;
	
	if (exec->process_cnt == 2)
		;
	else
		;
	return (0);
}