/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:08:19 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 15:50:32 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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

	new_env = malloc(sizeof(t_env));
	if (new_env == NULL)
	{
		printf("alloc error\n");
		exit(1);
	}
	init_env_dummy_node(new_env);
	env_key_size = get_env_key_size(env_str);
	new_env->str = ft_safe_strdup(env_str);
	new_env->key = ft_safe_substr(env_str, 0, env_key_size);
	new_env->value = ft_safe_substr(env_str, \
			ft_strchr_index(env_str, '=') + 1, \
			ft_strlen(env_str));
	new_env->next = NULL;
	return (new_env);
}

void	env_add(t_env *env_head, char *env_str)
{
	t_env	*curr;

	curr = env_head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_env_node(env_str);
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