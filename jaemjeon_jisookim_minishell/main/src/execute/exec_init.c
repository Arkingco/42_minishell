/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 15:38:04 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// pipe_cnt = process_cnt -1
size_t	count_process(t_exec *exec, t_cmd *cmd)
{
	size_t		process;

	process = 0;
	while (cmd)
	{
		process++;
		if (!cmd->next)
			break ;
		if (process == sizeof(size_t))
		{
			ft_putstr_fd("ERROR : process size too big. ", 2);
			exit(BAD_EXIT);
		}
		cmd = cmd->next;
	}
	cmd = exec->cmd_head; // put back cmd
	return (process);
}


t_exec	*init_exec(t_exec *exec, t_cmd *cmd)
{
	t_exec	*exec;
	exec = ft_calloc(1, sizeof(t_exec));
	if (!exec)
	{
		ft_putstr_fd("ERROR : calloc() function error. ", 2);
		free(exec);
		exit(BAD_EXIT);
	}
	exec->cmds = cmd;
	exec->cmd_head = cmd;
	exec->process_cnt = count_process(exec, cmd); // check number of pipe

	return (exec);
}
