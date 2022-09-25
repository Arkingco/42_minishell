/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:44:01 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 17:47:23 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	print_error_message(int has_minishell, char *s1, char *s2)
{
	if (has_minishell)
		ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
}

void	perror_with_header(char *string, int type)
{
	if (type == IDENTIFIER_ERR)
		print_error_message(TRUE, string, ": not a valid identifier");
	else if (type == MANY_ARG_ERR)
		print_error_message(TRUE, string, ": too many arguments");
	else if (type == CMD_NOT_FOUND_ERR)
		print_error_message(TRUE, string, ": command not found");
	else if (type == NOT_NUM_ARG_ERR)
		print_error_message(TRUE, string, ": numeric argument required");
	else if (type == SYNTAX_ERR)
		print_error_message(TRUE, "syntax error near unexpected token", \
																	string);
	else if (type == OPEN_FAIL_ERR)
		print_error_message(TRUE, "open fail file name", string);
	else if (type == OPEN_ERR)
		print_error_message(TRUE, string, ": No such file or directory");
	else if (type == HOME_SET_ERR)
		print_error_message(TRUE, "cd: HOME not set", 0);
}

void	perror_no_header(int type)
{
	if (type == CUR_PATH_ERR)
		print_error_message(FALSE,
							  "pwd: error retrieving current directory", 0);
	else if (type == GET_CWD_ERR)
		print_error_message(FALSE,
							  "getcwd: cannot access parent directories: \
									No such file or directory", 0);
	else if (type == CHANGE_DIR_ERR)
		print_error_message(FALSE,
							  "chdir: error retrieving current directory", 0);
}

void	process_errno(int errno_num, char *string, int type)
{
	g_errno = errno_num;
	if (type < ERR_COUNT / 2)
		perror_with_header(string, type);
	else
		perror_no_header(type);
}
