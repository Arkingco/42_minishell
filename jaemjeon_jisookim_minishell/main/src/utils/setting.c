/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:37:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 01:51:36 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_errno;

#include "../../include/minishell.h"

void	sigtermset(int mode)
{
	set_signal(mode);
	set_termios(mode);
}

void	printf_fd(int fd, char *arg, ...)
{

}

void	set_errno(int errno, int type)
{
	g_errno = errno;
	if (type == IDENTIFIER_ERR)
	{
		;
	}
	else if (type == MANY_ARG_ERR)
	{
		;
	}
	else if (type == CMD_NOT_FOUND_ERR)
	{
		;
	}
	else if (type == NOT_NUM_ARG_ERR)
	{
		;
	}
}

