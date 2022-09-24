/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 16:51:12 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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

static void	strjoin_slash_to_path(t_args_execve *p_args)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (p_args->path[i])
	{
		temp = p_args->path[i];
		p_args->path[i] = ft_safe_strjoin(p_args->path[i], "/");
		ft_safe_free(temp);
		i++;
	}
}

static void	process_path(t_args_execve *p_args, t_env *l_env)
{
	char	*str_path_value;
	
	str_path_value = get_env_value(l_env, "PATH");
	p_args->path = ft_split(str_path_value, ':');
	ft_check_error(E_LIBFT, (ssize_t)p_args->path);
	strjoin_slash_to_path(p_args);
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

static void	process_argv(t_parsing_list *l_parsing, t_args_execve *p_args,
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

static void	process_execve_args(t_parsing_list *l_parsing, 
				t_args_execve *p_args, t_env *l_env)
{
	int	num_args;

	process_path(p_args, l_env);
	num_args = count_num_args(l_parsing->l_simple_cmd);
	process_argv(l_parsing, p_args, num_args);

	//printf
	// int i = 0;
	// while (p_args->argv[i])
	// {
	// 	printf("%d simple cmd : %s\n", i,p_args->argv[i]);
	// 	i++;
	// }
}

static void	execve_cmd(t_args_execve *p_args)
{
	size_t	i;
	char	*file_path;

	i = 0;
	while (p_args->path[i])
	{
		file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
		// envp 넣기
		execve(file_path, p_args->argv, NULL);
		ft_safe_free(file_path);
		i++;
	}
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	
	printf("\n*exeuction*\n");
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, l_env);
	}
	else
	{
		printf("single & multi shell cmd\n\n");
		while (l_parsing)
		{
			process_execve_args(l_parsing, &args_execve, l_env);
			execve_cmd(&args_execve);
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
