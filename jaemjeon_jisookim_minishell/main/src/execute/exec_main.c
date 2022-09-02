/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 18:03:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_single_cmd(t_exec *exec)
{
	int	is_built_in;
	
	exec_single_check_built_in(exec);
	//execute with fork
		//make pipe
		//fork
		//execute in child process
		//wait_pid in parent process
		//wait_pid control
	
	return (0);
}

int	exec_multi_cmd(t_exec *exec)
{
	int	i;
	
	i = 0;
	while (exec->cmds)
	{
		if (i == 0) // 처음
		{
			exec_multi_first(exec);
		}
		else if (i == exec->process_cnt - 1) // 마지막
		{
			exec_multi_last(exec); // built in needs to work
		}
		else // 중간
		{
			exec_multi_middle(exec);
		}
		exec->cmds = exec->cmds->next;
		if (!exec->cmds)
			break ;
	}
	return (0);
}

int	execute(t_cmd *cmd)
{
	t_exec	*exec;

	exec = init_exec(exec, cmd);
	if (cmd && !cmd->next)
	{	
		exec_single_cmd(exec);
	}
	else
	{
		exec_multi_cmd(exec);
	}
	return (0);
}