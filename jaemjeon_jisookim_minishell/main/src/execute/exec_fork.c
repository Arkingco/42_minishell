/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:47 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 18:48:09 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int	exec_single_fork(t_exec *exec)
{
	pid_t	fork_ret;
	fork_ret = ft_fork();
	if (fork_ret == 0)
	{
		exec_child_process();
	}
	else
	{
		exec_parent_process();
	}
	
}

int	ezec_multi_fork(t_exec *exec)
{
	pid_t	fork_ret;
	fork_ret = ft_fork();
	if (fork_ret == 0)
	{
		exec_child_process();
	}
	else
	{
		exec_parent_process();
	}
	
}