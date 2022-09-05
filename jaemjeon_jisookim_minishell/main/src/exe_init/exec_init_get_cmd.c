/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/06 01:04:06 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_cmd_count(t_exec *exec)
{
	// int	i;
	// int	simple_cmd_count;
	
	// i = 0;
	// simple_cmd_count = 0;
	// while (exec->cmds)
	// {
	// 	while (exec->cmds->simple_cmd)
	// 	{
	// 		simple_cmd_count++;
	// 		if (exec->cmds->simple_cmd->next)
	// 			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
	// 		else
	// 			break ;
	// 	}
	// 	exec->cmd_cnt[i] = exec->cmds->simple_cmd;
	// 	if (exec->cmds->next)
	// 	{
	// 		exec->cmds = exec->cmds->next;
	// 		i++;
	// 	}
	// 	else
	// 		break ;
	// }
	// return ;
}

void	make_ptr_execve_cmds(t_exec *exec)
{
	// int	i;
	// int	j;

	// i = 0;
	// j = 0;
	// exec->execve_cmds[i] = ft_calloc(1, sizeof(char *) * exec->cmd_cnt[i] + 1); // divide with cmd
	// if (!exec->execve_cmds[i])
	// {
	// 	ft_putstr_fd("ERROR : calloc() error while making execve_cmds. \n", 2);
	// 	free(exec->execve_cmds[i]);
	// }
	// while (i < exec->cmd_cnt[i])
	// {
	// 	if (exec->cmds->simple_cmd && exec->cmds->simple_cmd->next)
	// 	{
	// 		exec->execve_cmds[i] = ft_strdup(exec->cmds->simple_cmd);
	// 		exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
	// 	}
	// }
	// i++;
	// free(exec->execve_cmds);
	// exit(1);
}

// 단위 : one cmd, in one process.
char	***get_execve_cmds(t_exec *exec)
{	
	// int		i;
	
	// i = 0;
	// get_cmd_count(exec);
	// printf("\n\n========================\n");
	// while (exec->cmd_cnt[i])
	// {
	// 	printf("cmd_count : %d\n", exec->cmd_cnt[i]);
	// 	i++;
	// }
	// printf("\n========================\n\n");

	// i = 0;
	// make_ptr_execve_cmds(exec);
	// while(i < exec->cmd_count && exec->cmds)
	// {
	// 	exec->execve_cmds[i] = exec->cmds->simple_cmd->string_value;
	// 	exec->cmds = exec->cmds->next;
	// 	i++;
	// }
	// exec->execve_cmds[i] = 0;
	// exec->cmds = exec->cmd_head;
	return (&exec->execve_cmds);
}