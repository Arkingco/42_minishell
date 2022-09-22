/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:59 by kipark            #+#    #+#             */
/*   Updated: 2022/09/21 07:06:36 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"parser.h"
#include"libft.h"

void	built_in_echo(t_simple_cmd *simple_cmd)
{
	int n_flag;
	t_simple_cmd *this_simple_cmd;

	n_flag = 1;
	this_simple_cmd = this_simple_cmd->next;
	if (ft_strncmp(this_simple_cmd->str, "-n", ft_strlen("-n") + 1))
	{
		n_flag = 0;
		this_simple_cmd = this_simple_cmd->next;
	}
	while (this_simple_cmd)
	{
		printf("%s ",this_simple_cmd->str);
		this_simple_cmd = this_simple_cmd->next;
	}
	if (n_flag)
		printf("\n");
	//
	//	에러상태 넣기
	//
}
