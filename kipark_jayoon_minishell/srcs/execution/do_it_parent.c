/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:22:13 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/28 17:53:15 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	do_it_parent(int *fd, t_info_process *info_proc)
{
	if (info_proc->num_proc > 1)
	{
		// 처음이 아닐 때 닫기
		if (info_proc->idx_curr_proc != 0)
			safe_close(fd[2]);
		// 마지막 프로세스가 아닐 때
		if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
		{
			safe_close(fd[1]);
			fd[2] = fd[0];
		}
	}
}
