/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execve_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:16:29 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/26 14:16:11 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"

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

static void	init_path(t_args_execve *p_args, t_env *l_env)
{
	char	*str_path;
	
	str_path = get_env_value(l_env, "PATH");
	p_args->path = ft_split(str_path, ':');
	ft_safe_free(str_path);
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

static void	init_argv(t_parsing_list *l_parsing, t_args_execve *p_args,
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

void	init_execve_args(t_parsing_list *l_parsing, t_args_execve *p_args,
			t_env *l_env)
{
	int	num_args;

	init_path(p_args, l_env);
	num_args = count_num_args(l_parsing->l_simple_cmd);
	init_argv(l_parsing, p_args, num_args);
}
