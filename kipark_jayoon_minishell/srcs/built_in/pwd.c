/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:50 by kipark            #+#    #+#             */
/*   Updated: 2022/09/25 14:45:15 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>

void	built_in_pwd(t_simple_cmd *simple_cmd)
{
	char	*curr_path;

	if (simple_cmd->str == NULL)
		return ;
	curr_path = getcwd(NULL, 0);
	if (curr_path)
	{
		printf("%s\n",curr_path);
		free(curr_path);
	}
	else
	{
		// error 띄우기
		// errono 출력
		printf("NULL\n");
	}
}
