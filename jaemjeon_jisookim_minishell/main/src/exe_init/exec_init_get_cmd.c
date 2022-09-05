/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:19 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_cmd_count(t_exec *exec)
{
	int	count;
	
	count = 0;
	while (exec->cmds->next)
	{
		count++;
	}
	count++;
	return (count);
}

void	make_double_ptr_execve_cmds(t_exec *exec, int cmd_count)
{
	exec->execve_cmds = ft_calloc(1, sizeof(char *) * cmd_count + 1);
	if (!exec->execve_cmds)
	{
		ft_putstr_fd("ERROR : calloc() error while making execve_cmds. \n", 2);
		free(exec->execve_cmds);
		exit(BAD_EXIT);
	}
}

// 단위 : one cmd, in one process.
char	**get_execve_cmds(t_exec *exec)
{	
	int		i;
	int		cmd_count;
	
	i = 0;
	cmd_count = get_cmd_count(exec);
	make_double_ptr_execve_cmds(exec, cmd_count);
	while(i < cmd_count && exec->cmds)
	{
		exec->execve_cmds[i] = exec->cmds->simple_cmd->string_value;
		exec->cmds = exec->cmds->next;
		i++;
	}
	exec->execve_cmds[i] = 0;
	exec->cmds = exec->cmd_head;
	return (exec->execve_cmds);
}