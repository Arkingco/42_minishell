/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:44:01 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/28 12:41:23 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <dirent.h>

extern int	g_errno;

void	print_error_message(int has_minishell, char *s1, char *s2)
{
	if (has_minishell)
		ft_putstr_fd("minishell: ", 2);
	if (s1 != NULL)
		ft_putstr_fd(s1, 2);
	if (s2 != NULL)
		ft_putstr_fd(s2, 2);
	ft_putchar_fd('\n', 2);
}

void	perror_open_fail(char *string)
{
	DIR		*hello;
	int		temp;

	temp = errno;
	hello = opendir(string);
	if (hello)
	{
		print_error_message(TRUE, string, ": is a directory");
		closedir(hello);
	}
	else
	{
		if (temp == 13)
			print_error_message(TRUE, string, ": Permission denied");
		else
			print_error_message(TRUE, string, ": no such file or directory");
	}
	errno = temp;
}

void	perror_with_header(char *string, int type)
{
	if (type == IDENTIFIER_ERR)
		print_error_message(TRUE, string, ": not a valid identifier");
	else if (type == MANY_ARG_ERR)
		print_error_message(TRUE, string, ": too many arguments");
	else if (type == CMD_NOT_FOUND_ERR)
		print_error_message(TRUE, string, ": command not found");
	else if (type == OPEN_ERR)
		perror_open_fail(string);
	else if (type == NOT_NUM_ARG_ERR)
		print_error_message(TRUE, string, ": numeric argument required");
	else if (type == SYNTAX_ERR)
		print_error_message(TRUE, "syntax error near unexpected token", \
																	string);
	else if (type == OPEN_FAIL_ERR)
		print_error_message(TRUE, "open fail file name", string);
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
	if (type == CUR_PATH_ERR || type == GET_CWD_ERR || type == CHANGE_DIR_ERR)
		perror_no_header(type);
	else
		perror_with_header(string, type);
}
