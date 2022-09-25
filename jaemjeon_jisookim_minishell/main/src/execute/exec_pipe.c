/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:51:29 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 23:31:55 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_pipe_before_next_cmd(int *fd)
{
	if (fd[2] != -1)
		ft_close(fd[2]);
	fd[2] = fd[0];
	if (fd[1] != -1)
		ft_close(fd[1]);
	fd[1] = -1;
	fd[0] = -1;
	return ;
}
