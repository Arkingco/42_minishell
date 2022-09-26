/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:43 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 12:26:04 by kipark           ###   ########seoul.kr  */
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

void	built_in_exit(t_simple_cmd *simple_cmd)
{
	if (simple_cmd->next == NULL)
		exit(0);
	else if (simple_cmd->next->next != NULL)
	{
		printf("exit: too many arguments\n");
		exit(1); // exit 없이 error 상태 1로 바꾸기
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
	return ;
}
