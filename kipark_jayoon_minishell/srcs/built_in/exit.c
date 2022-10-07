/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:43 by kipark            #+#    #+#             */
/*   Updated: 2022/10/07 13:50:08 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "exit_status.h"
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
	if (simple_cmd->next == NULL)
	{
		ft_putendl_fd("exit", 1);
		exit(g_exit_status);
	}
	else if (simple_cmd->next->next != NULL)
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (g_exit_status = 1);
	}
	else
	{
		if (is_all_digit(simple_cmd->next->str))
		{
			ft_putendl_fd("exit", 1);
			exit(ft_atoi(simple_cmd->next->str));
		}
		else
		{
			ft_multi_putendl_fd("exit\nminishell: exit: ", \
					simple_cmd->next->str, ": numeric argument required", 2);
			exit(255);
		}
	}
	return (g_exit_status = 0);
}
