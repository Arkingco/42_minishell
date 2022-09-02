/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 16:10:17 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// pipe_cnt = process_cnt -1
int	count_process(t_exec *exec)
{
	int		process;

	process = 0;
	while (exec->cmds)
	{
		process++;
		if (!exec->cmds->next)
			break ;
		if (process == sizeof(int))
		{
			ft_putstr_fd("ERROR : process size too big. ", 2);
			exit(BAD_EXIT);
		}
		exec->cmds = exec->cmds->next;
	}
	exec->cmds = exec->cmd_head; // put back cmd
	return (process);
}


t_exec	*init_exec(t_exec *exec, t_cmd *cmd)
{
	exec = ft_calloc(1, sizeof(t_exec));
	if (!exec)
	{
		ft_putstr_fd("ERROR : calloc() function error. ", 2);
		free(exec);
		exit(BAD_EXIT);
	}
	exec->cmds = cmd;
	exec->cmd_head = cmd;
	exec->process_cnt = count_process(exec);

	return (exec);
}
