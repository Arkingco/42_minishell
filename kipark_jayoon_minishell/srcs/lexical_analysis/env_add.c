/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:08:19 by kipark            #+#    #+#             */
/*   Updated: 2022/10/10 11:06:10 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static t_env	*get_dup_env(t_env *env, char *str)
{
	char		*str_key;
	t_env		*this_env;
	int			str_key_size;

	str_key = get_env_key(str);
	str_key_size = ft_strlen(str_key);
	this_env = env->next;
	while (this_env)
	{
		if (ft_strncmp(this_env->key, str_key, str_key_size + 1) == 0)
		{
			free(str_key);
			return (this_env);
		}
		this_env = this_env->next;
	}
	free(str_key);
	return (NULL);
}

static t_env	*new_env_node(char *env_str)
{
	t_env		*new_env;
	const int	equal_index = ft_strchr_index(env_str, '=');

	new_env = ft_safe_malloc(sizeof(t_env));
	new_env->str = ft_safe_strdup(env_str);
	new_env->key = ft_safe_substr(env_str, 0, get_env_key_size(env_str));
	if (!equal_index)
		new_env->value = NULL;
	else
		new_env->value = ft_safe_substr(env_str, \
								equal_index + 1, ft_strlen(env_str));
	new_env->next = NULL;
	return (new_env);
}

void	env_add(t_env *env_head, char *env_str)
{
	t_env	*curr;
	t_env	*dup_env;

	dup_env = get_dup_env(env_head, env_str);
	if (dup_env)
	{
		if ((size_t)get_env_key_size(env_str) == ft_strlen(env_str))
			return ;
		free(dup_env->str);
		if (dup_env->value != NULL)
			free(dup_env->value);
		dup_env->str = ft_strdup(env_str);
		dup_env->value = ft_safe_substr(env_str, \
					ft_strchr_index(env_str, '=') + 1, ft_strlen(env_str));
		return ;
	}
	curr = env_head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_env_node(env_str);
}
