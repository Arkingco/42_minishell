/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:59:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/30 16:35:06 by jisookim         ###   ########.fr       */
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



void	child_process(t_exec *exec, int idx)
{
	
}