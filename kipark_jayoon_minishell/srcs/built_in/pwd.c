/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:50 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 15:42:53 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int	built_in_pwd(t_simple_cmd *simple_cmd)
{
	int		pwd_exit_status;
	char	*curr_path;

	if (simple_cmd->str == NULL)
		return (pwd_exit_status = 0);
	curr_path = getcwd(NULL, 0);
	if (curr_path)
	{
		printf("%s\n", curr_path);
		free(curr_path);
	}
	else
	{
		strerror(errno);
		return (pwd_exit_status = errno);
	}
	return (pwd_exit_status = 0);
}
