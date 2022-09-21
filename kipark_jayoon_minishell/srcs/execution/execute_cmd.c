/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/21 21:30:04 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>

int	check_our_program()
{}

static int	is_single_cmd(t_parsing_list *next)
{
	if (next == NULL)
		return (1);
	return (0);
}

void	set_in_out_fd(t_parsing_list *l_parsing, int *pipe_fd)
{
	int in_fd;
	int out_fd;

	in_fd = 0;
	out_fd = 1;

	if (pipe_fd[2] != 0)
		in_fd = pipe_fd[2];
		
	
}

void	execute_cmd(t_parsing_list *l_parsing)
{
	int pipe_fd[3];

	pipe_fd[0] = 0;
	pipe_fd[1] = 1;
	pipe_fd[2] = 3;

	0
	1
	2

	pipe()
	3 read
	4 write

	pipe_fd[]
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		
	}
	else
	{
		while (l_parsing)
		{
			
			l_parsing = l_parsing->next;
		}
	}
}
