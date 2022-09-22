/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:37:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 01:35:30 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_errno;

#include "../../include/minishell.h"

void	sigtermset(int mode)
{
	set_signal(mode);
	set_termios(mode);
}

void	set_errno(int errno, int type)
{
	g_errno = errno;
	
}

