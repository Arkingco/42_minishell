/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 16:25:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_single_cmd(t_exec *exec)
{
	int	is_built_in;
	
	is_built_in = check_built_in(exec);
	if (is_built_in)
	{
		
	}
	else
	{
		
	}
	
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
			exec_multi_last(exec);
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
	else if (cmd)
	{
		exec_multi_cmd(exec);
	}
	return (0);
}