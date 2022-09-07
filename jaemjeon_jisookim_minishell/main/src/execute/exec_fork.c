/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:47 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:54:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// divide handler depending parameter 'i' - first / middle / last
void	exec_process_dup2_handler(t_exec *exec, int i)
{
	return ;
}

int	exec_main_forking_process(t_exec *exec)
{
	pid_t	fork_ret;
	int		i;

	i = 0;
	while (i < exec->process_cnt)
	{
		fork_ret = ft_fork();
		exec_process_dup2_handler(exec, i);
	}
	// if fork_ret == 0, it's child process


	// needs to return pid;

	return (0);
}
