/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/03 13:46:02 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_single_cmd(t_exec *exec, t_envlst *env)
{
	int		is_built_in;
	pid_t	pid;
	
	exec_single_check_built_in(exec);
	pid = ft_fork();
	if (pid == 0)
	{
		ft_exceve(exec->final_path, exec->exceve_cmd, env);
	}
	//execute in child process
	//wait_pid in parent process
	//wait_pid control
	
	return (0);
}

int	exec_multi_cmd(t_exec *exec, t_envlst *env)
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

int	execute(t_cmd *cmd, t_envlst *env)
{
	t_exec	*exec;

	exec = init_exec(exec, cmd, env);
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