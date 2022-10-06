/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:56 by kipark            #+#    #+#             */
/*   Updated: 2022/10/06 11:17:26 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "parser.h"
#include "libft.h"
#include <stdio.h>

static void	env_node_free(t_env *env_node)
{
	free(env_node->key);
	free(env_node->str);
	if (env_node->value != NULL)
		free(env_node->value);
	free(env_node);
}

static void	delete_env_node(char *str, t_env *env)
{
	char	*str_key;
	t_env	*this_env;
	t_env	*next_env;

	str_key = get_env_key(str);
	this_env = env;
	while (this_env->next != NULL)
	{
		if (ft_strncmp(this_env->next->key, \
										str_key, ft_strlen(str_key) + 1) == 0)
		{
			next_env = this_env->next->next;
			env_node_free(this_env->next);
			this_env->next = next_env;
			break ;
		}
		this_env = this_env->next;
	}
	free(str_key);
	return ;
}

int	built_in_unset(t_simple_cmd *simple_cmd, t_env *env)
{
	int	unset_exit_status;

	unset_exit_status = 0;
	if (simple_cmd->next == NULL)
		return (0);
	simple_cmd = simple_cmd->next;
	while (simple_cmd)
	{
		if ((size_t)get_env_key_size(simple_cmd->str) != \
													ft_strlen(simple_cmd->str))
		{
			ft_multi_putendl_fd("minishell: '", simple_cmd->str, \
											"':not a valid identifier", 2);
			unset_exit_status = 1;
		}
		else
			delete_env_node(simple_cmd->str, env);
		simple_cmd = simple_cmd->next;
	}
	return (unset_exit_status);
}
