/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:22:13 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "parser.h"

void	do_it_parent(int *fd, t_info_cmd *info_cmd)
{
	if (info_cmd->this_l_input)
	{
		while (info_cmd->this_l_input)
		{
			if (info_cmd->this_l_input->type == T_HERE_DOC)
				info_cmd->l_here_doc = info_cmd->l_here_doc->next;
			info_cmd->this_l_input = info_cmd->this_l_input->next;
		}
	}
	if (info_cmd->num_proc > 1)
	{
		if (info_cmd->idx_curr_proc != 0)
		{
			safe_close(fd[2]);
			fd[2] = 0;
		}
		if (!is_last_cmd(info_cmd))
		{
			safe_close(fd[1]);
			fd[1] = 1;
			fd[2] = fd[0];
		}
	}
}
