/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:59 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 17:27:04 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"parser.h"
#include"libft.h"
#include<stdio.h>

static void	return_new_line()
{
	printf("\n");
	return ;
}

void	built_in_echo(t_simple_cmd *simple_cmd)
{
	int n_flag;

	if (simple_cmd->next == NULL)
		return (return_new_line());
	n_flag = 1;
	simple_cmd = simple_cmd->next;
	if (!ft_strncmp(simple_cmd->str, "-n", 3))
	{
		n_flag = 0;
		simple_cmd = simple_cmd->next;
	}
	while (simple_cmd)
	{
		printf("%s ",simple_cmd->str);
		simple_cmd = simple_cmd->next;
	}
	if (n_flag)
		printf("\n");
	//
	//	에러상태 넣기
	//
}
