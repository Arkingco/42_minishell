/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:59 by kipark            #+#    #+#             */
/*   Updated: 2022/10/04 16:55:02 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"parser.h"
#include"libft.h"
#include<stdio.h>

static int	return_new_line(int exit_status)
{
	printf("\n");
	return (exit_status);
}

int	built_in_echo(t_simple_cmd *simple_cmd)
{
	int	echo_n_option;
	int	echo_exit_status;

	echo_exit_status = 0;
	echo_n_option = 1;
	if (simple_cmd->next == NULL)
		return (echo_exit_status = return_new_line(0));
	simple_cmd = simple_cmd->next;
	if (!ft_strncmp(simple_cmd->str, "-n", 3))
	{
		echo_n_option = 0;
		simple_cmd = simple_cmd->next;
	}
	while (simple_cmd)
	{
		printf("%s ", simple_cmd->str);
		simple_cmd = simple_cmd->next;
	}
	// ft_putendl로 변경 해야함
	if (echo_n_option)
		printf("\n");
	return (echo_exit_status = 0);
}
