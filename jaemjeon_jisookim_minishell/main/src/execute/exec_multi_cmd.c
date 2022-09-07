/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:33:44 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int	exec_multi_first(t_exec *exec)
{
	
	//pipe
	//fork -> get pid
	//dup2
	//if pid == 0 <- child process
	
	return (0);
}

int	exec_multi_last(t_exec *exec)
{
	return (0);
}

int	exec_multi_middle(t_exec *exec)
{
	exec_multi_check_built_in(exec);
	return (0);
}
