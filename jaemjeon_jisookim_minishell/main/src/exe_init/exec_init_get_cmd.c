/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/10 10:35:35 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_token_count(t_exec *exec)
{
	int	i;

	i = 0;
	exec->token_cnt = ft_calloc(1, sizeof(int *) * exec->process_cnt);
	if (!exec->token_cnt)
	{
		ft_putstr_fd("ERROR : calloc() function error. \n", 2);
		free(exec->token_cnt);
		exit(1);
	}
	while (i < exec->process_cnt)
	{
		exec->token_cnt[i] = get_simple_cmd_count(exec, i);
		i++;
	}
	return ;
}


int	get_simple_cmd_count(t_exec *exec, int i)
{
	int		cmd_count;
	void	*backup_exec_cmd;
	void	*backup_simple_cmd_head;
	
	cmd_count = 0;
	backup_exec_cmd = exec->cmds;
	tools_move_cmd(exec, i);
	backup_simple_cmd_head = exec->cmds->simple_cmd;
	while (exec->cmds->simple_cmd)  //simple cmd이동
	{
		if (exec->cmds->simple_cmd->next)
		{
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
			cmd_count++;
		}
		else
		{
			exec->cmds->simple_cmd = backup_simple_cmd_head;
			cmd_count++;
			break ;
		}	
	}
	exec->cmds = backup_exec_cmd;
	return (cmd_count);
}
