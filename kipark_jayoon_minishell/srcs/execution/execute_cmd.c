/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/22 15:55:23 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "built.h"
#include <stdio.h>

static int	is_single_cmd(t_parsing_list *next)
{
	if (next == NULL)
		return (1);
	return (0);
}

// static void	set_in_out_fd(t_parsing_list *l_parsing, int *pipe_fd)
// {
// 	int in_fd;
// 	int out_fd;

// 	in_fd = 0;
// 	out_fd = 1;

// 	if (pipe_fd[2] != 0)
// 		in_fd = pipe_fd[2];
		
	
// }

void	execute_cmd(t_parsing_list *l_parsing)
{
	// int pipe_fd[3];

	// pipe_fd[0] = 0;
	// pipe_fd[1] = 1;
	// pipe_fd[2] = 3;

	// 0
	// 1
	// 2

	// pipe()
	// 3 read
	// 4 write

	// pipe_fd[]
	printf("-------------exeucte--------------------\n");
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
	}
	else
	{
		printf("single & multi shell cmd\n");
		while (l_parsing)
		{
			
			l_parsing = l_parsing->next;
		}
	}
	printf("----------------------------------------\n\n\n");

}
