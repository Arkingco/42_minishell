/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:59:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/31 14:29:18 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	put_info_to_pipe(t_cmd *cmd, t_exec *exec)
{
	// child process 가 들어올 것!
	//if first
	ft_close(exec->pipe_fd[0]); 
	ft_dup2(exec->pre_read_fd, 0); 
	ft_close(exec->pre_read_fd);
	ft_dup2(exec->pipe_fd[1], 1);
	ft_close(exec->pipe_fd[1]);
	//execute
}

// check simple, connect> subshell?  
void	child_process(t_exec *exec, int idx, t_cmd *cmd)
{
	int	i;
	static char *built_in[7] = {"cd", "echo", "env", "exit", \
								"export", "pwd", "unset"};
	i = 0;
	while (cmd)
	{
		if (cmd->simple_cmd == built_in[i])(// built-in, 포크를 뜨지 않고 실행)
		{
			exec->is_builtin = 1;
			//execute
		}
		else
		{
			//fork
			//execute
			;(//전부 포크를 뜬 다음에 실행)
		}
		cmd = cmd->next;
	}
}