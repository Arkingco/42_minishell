/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:46:06 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 18:58:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	single_pipe_dup2(t_exec *exec)
{
	// // default : child process pipe 연결
	// 
	// ft_dup2(STDOUT_FD, exec->pipe_fd[PIPE_IN]);
	// close(STDOUT_FD);
	// ft_dup2(STDIN_FD, exec->pipe_fd[PIPE_OUT]);
	// close(STDIN_FD);
	// // redirection handling (input)
	// // redirection handling (output)
	return (0);
}

int	multi_pipe_dup2(t_exec *exec)
{
	// if ()
	return (0);
}