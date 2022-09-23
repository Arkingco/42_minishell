/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:37:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 11:25:30 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_errno;

#include "../../include/minishell.h"

void	sigtermset(int mode)
{
	set_signal(mode);
	set_termios(mode);
}

void	process_errno(int errno_num, char *string, int type)
{
	g_errno = errno_num;
	if (type == IDENTIFIER_ERR)
		printf_fd(2, "MINISHELL : %s not a valid identifier\n", string);
	else if (type == MANY_ARG_ERR)
		printf_fd(2, "minishell: %s too many arguments\n", string);
	else if (type == CMD_NOT_FOUND_ERR)
		printf_fd(2, "minishell: %s command not found\n", string);
	else if (type == NOT_NUM_ARG_ERR)
		printf_fd(2, "minishell: %s numeric argument required\n", string);
	else if (type == SYNTAX_ERR)
		printf_fd(2, "minishell: syntax error near unexpected token `%s'\n", \
																	string);
	else if (type == OPEN_FAIL_ERR) 
		printf_fd(2, "minishell: open fail file name '%s'\n", string);
}

