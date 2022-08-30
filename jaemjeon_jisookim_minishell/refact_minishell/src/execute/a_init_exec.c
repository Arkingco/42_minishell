/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:54:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/30 14:50:32 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	count_process(t_cmd *cmd) // 파이프는 프로세스 -1
{
	size_t		process;
	t_cmd	*backup_head_cmd;

	process = 0;
	backup_head_cmd = cmd;
	while (cmd)
	{
		process++;
		if (!cmd->next)
			break ;
		if (process == sizeof(size_t))
			break ; // error, size overflow
		cmd = cmd->next;
	}
	cmd = backup_head_cmd; // put back cmd
	return (process);
}

// 파이프 단위로 체크
int	check_heredoc(t_exec *exec, t_cmd *cmd)
{
	if (!cmd->redirect_input)
		return (0);
	while (cmd->redirect_input)
	{
		if (cmd->redirect_input->type == HEREDOC)
			return (1);
		else
			cmd = cmd->redirect_input;
	}
	return (0);
}


void	init_exec(t_exec *exec, t_cmd *cmd)
{
	t_exec	*exec;

	exec->process_cnt = count_process(cmd); // check number of pipe
	exec->heredoc_flag = check_heredoc(exec, cmd);

	return ;
}
