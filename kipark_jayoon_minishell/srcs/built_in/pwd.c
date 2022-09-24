/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:50 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 20:12:05 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>

void	built_in_pwd()
{
	char	*curr_path;

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