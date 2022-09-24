/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 19:54:44 by jayoon           ###   ########.fr       */
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
}

static void	execve_cmd(t_args_execve *p_args, char **envp)
{
	size_t	i;
	char	*file_path;

	i = 0;
	while (p_args->path[i])
	{
		file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
		execve(file_path, p_args->argv, envp);
		ft_safe_free(file_path);
		i++;
	}
}

static size_t	count_env(t_env *l_env)
{
	size_t	num_env;

	num_env = 0;
	while (l_env)
	{
		num_env++;
		l_env = l_env->next;
	}
	return (num_env);
}

static void	put_in_str_in_curr_envp(char **curr_envp, t_env *l_env)
{
	size_t	i;

	i = 0;
	while (l_env)
	{
		curr_envp[i] = l_env->str;
		i++;
		l_env = l_env->next;
	}
	curr_envp[i] = NULL;
}

static char	**init_curr_envp(t_env *l_env)
{
	char	**curr_envp;
	size_t	num_env;

	num_env = count_env(l_env);
	curr_envp = ft_safe_malloc(sizeof(char *) * (num_env + 1));
	put_in_str_in_curr_envp(curr_envp, l_env);
	return (curr_envp);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	char			**curr_envp;
	
	printf("\n*exeuction*\n");
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, l_env);
	}
	else
	{
		printf("single & multi shell cmd\n\n");
		l_env = l_env->next;
		curr_envp = init_curr_envp(l_env);
		while (l_parsing)
		{
			process_execve_args(l_parsing, &args_execve, l_env);
			execve_cmd(&args_execve, curr_envp);
			l_parsing = l_parsing->next;
		}
		ft_safe_free(curr_envp);
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
