/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:43 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 15:58:52 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int	built_in_exit(t_simple_cmd *simple_cmd)
{
	int exit_exit_status;

	exit_exit_status = 0;
	if (simple_cmd->next == NULL)
		exit(0);
	else if (simple_cmd->next->next != NULL)
	{
		printf("exit: too many arguments\n");
		return (exit_exit_status = 1);
	}
	else
	{
		if (is_all_digit(simple_cmd->next->str))
		{
			printf("exit\n");
			exit(ft_atoi(simple_cmd->next->str));
		}
		else
		{
			printf("exit\nbash: exit: %s: numeric argument required\n", \
														simple_cmd->next->str);
			exit(255);
		}
	}
	return (exit_exit_status = 0);
}
