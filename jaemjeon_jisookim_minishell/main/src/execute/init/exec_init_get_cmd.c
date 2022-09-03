/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/03 14:57:07 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	make_double_ptr_execve_cmds(t_exec *exec, int cmd_count)
{
	exec->execve_cmds = ft_calloc(1, sizeof(char *) * cmd_count + 1);
	if (!exec->execve_cmds)
	{
		ft_putstr_fd("ERROR : calloc() error while making execve_cmds. \n", 2);
		free(exec->execve_cmds);
		exit(BAD_EXIT);
	}
	exec->execve_cmds[cmd_count][0] = 0;
}

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

// 단위 : one cmd, in one process.
char	**get_execve_cmds(t_exec *exec)
{	
	int		i;
	int		cmd_count;
	char	*word;
	
	i = 0;
	cmd_count = get_cmd_count(exec);
	make_double_ptr_execve_cmds(exec, cmd_count);
	while(i < cmd_count)
	{
		word = ft_strdup(exec->cmds->simple_cmd); // needs to free word
		if (!word)
			exit(1);
		exec->execve_cmds[i] = word;
		exec->cmds = exec->cmds->next;
		i++;
	}
	exec->cmds = exec->cmd_head;
	return (exec->execve_cmds);
}