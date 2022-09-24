/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:51:29 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 10:57:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_pipe_before_next_cmd(t_cmd *cur_cmd, int *fd)
{
	if (fd[BEFORE_INPUT_FD] != -1)
		ft_close(fd[BEFORE_INPUT_FD]);
	fd[BEFORE_INPUT_FD] = fd[MULTI_PIPE_OUTPUT];
	if (fd[MULTI_PIPE_INPUT] != -1)
		ft_close(fd[MULTI_PIPE_INPUT]);
	fd[MULTI_PIPE_INPUT] = -1;
	fd[MULTI_PIPE_OUTPUT] = -1;
	return ;
}
