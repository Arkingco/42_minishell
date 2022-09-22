/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/22 18:23:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
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

static void	parse_simple_cmd(t_parsing_list *l_parsing, t_args_execve *p_args)
{
	int	i;

	i = 0;
	p_args->file_path = l_parsing->l_simple_cmd->str;
	while (l_parsing->l_simple_cmd)
	{
		p_args->argv[i]
		l_parsing->l_simple_cmd = l_parsing->l_simple_cmd->next;
	}
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *curr_envp)
{
	t_args_execve	args_execve;
	
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
			parse_simple_cmd(l_parsing, &args_execve);
			execve("file path", "argv", curr_envp);
			l_parsing = l_parsing->next;
		}
	}
	printf("----------------------------------------\n\n\n");

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
