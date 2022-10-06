/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:04:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 18:05:43 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_last_cmd(t_info_cmd *info_cmd)
{
	if (info_cmd->idx_curr_proc == info_cmd->num_proc - 1)
		return (1);
	return (0);
}
