/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:22:13 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 16:12:13 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	do_it_parent(int *fd, t_info_process *info_proc)
{
	if (info_proc->num_proc > 1)
	{
		if (info_proc->idx_curr_proc != 0)
			safe_close(fd[2]);
		if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
		{
			safe_close(fd[1]);
			fd[2] = fd[0];
		}
	}
}