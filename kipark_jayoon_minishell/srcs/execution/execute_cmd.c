/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/23 17:53:37 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "parser.h"
#include "libft.h"
#include "built.h"

// printf
#include <stdio.h>

static int	is_single_cmd(t_parsing_list *next)
{
	if (next == NULL)
		return (1);
	return (0);
}

static void	parse_file_path(t_parsing_list *l_parsing, t_args_execve *p_args)
{
	p_args->path = l_parsing->l_simple_cmd->str;
}

static int	count_num_args(t_simple_cmd *l_simple_cmd)
{
	int	num;

	num = 0;
	while (l_simple_cmd)
	{
		num++;
		l_simple_cmd = l_simple_cmd->next;
	}
	return (num);
}

static void	parse_argv(t_parsing_list *l_parsing, t_args_execve *p_args,
				int num_args)
{
	int	i;

	i = 0;
	p_args->argv = ft_safe_malloc(sizeof(char *) * (num_args + 1));
	while (l_parsing->l_simple_cmd)
	{
		p_args->argv[i] = l_parsing->l_simple_cmd->str;
		i++;
		l_parsing->l_simple_cmd = l_parsing->l_simple_cmd->next;
	}
	p_args->argv[i] = NULL;
}

static void	parse_simple_cmd(t_parsing_list *l_parsing, t_args_execve *p_args)
{
	int	num_args;

	parse_file_path(l_parsing, p_args);
	
	//printf
	printf("path : %s\n", p_args->path);

	num_args = count_num_args(l_parsing->l_simple_cmd);
	parse_argv(l_parsing, p_args, num_args);

	//printf
	int i = 0;
	while (p_args->argv[i])
	{
		printf("%d simple cmd : %s\n", i,p_args->argv[i]);
		i++;
	}
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *curr_envp)
{
	t_args_execve	args_execve;
	
	printf("\n*exeuction*\n");
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, curr_envp);
	}
	else
	{
		printf("single & multi shell cmd\n\n");
		while (l_parsing)
		{
			parse_simple_cmd(l_parsing, &args_execve);
			// execve("file path", "argv", curr_envp);
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
