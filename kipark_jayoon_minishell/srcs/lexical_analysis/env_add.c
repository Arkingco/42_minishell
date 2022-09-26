/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:08:19 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 12:30:00 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static t_env *get_dup_env(t_env *env, char *str)
{
	int		str_key_size;
	char	*str_key;
	t_env	*this_env;

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

void	init_env_dummy_node(t_env *new_env)
{
	new_env->str = NULL;
	new_env->key = NULL;
	new_env->value = NULL;
	new_env->next = NULL;
}

t_env *new_env_node(char *env_str)
{
	t_env	*new_env;
	int		env_key_size;
	int		env_str_eqaul_index;

	new_env = ft_safe_malloc(sizeof(t_env));
	init_env_dummy_node(new_env);
	env_key_size = get_env_key_size(env_str);
	env_str_eqaul_index = ft_strchr_index(env_str, '=');
	new_env->str = ft_safe_strdup(env_str);
	new_env->key = ft_safe_substr(env_str, 0, env_key_size);
	if (!env_str_eqaul_index)
		new_env->value = ft_strdup("");
	else
		new_env->value = ft_safe_substr(env_str, \
								env_str_eqaul_index + 1, ft_strlen(env_str));
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
		free(dup_env->str);
		free(dup_env->value);
		///
		/// value 비어 있을 때 처리 해야함
		/// 
		dup_env->str = ft_strdup(env_str);
		dup_env->value = ft_safe_substr(env_str, \
					ft_strchr_index(env_str, '=') + 1, ft_strlen(env_str));
	}
	else
	{
		curr = env_head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_env_node(env_str);
	}
}

void	set_env_list(t_env *env_head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		env_add(env_head, envp[i]);
		++i;
	}
}