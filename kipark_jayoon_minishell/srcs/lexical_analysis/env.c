/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/08/27 17:03:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"libft.h"
#include"env.h"

void	print_env_list(t_env *env_head)
{
	t_env *env_list;

	env_list = env_head->next;
	while (env_list)
	{
		printf("%s\n", env_list->str);
		env_list = env_list->next;
	}
}


void	init_env_dummy_node(t_env *new_env)
{
	new_env->next = NULL;
	new_env->str = NULL;
}

t_env *new_env_node(char *env_str)
{
	t_env *new_env;

	new_env = malloc(sizeof(t_env));
	if (new_env == NULL)
		return (NULL);
	init_env_dummy_node(new_env);
	new_env->str = env_str;
	return (new_env);
}

void	env_add(t_env *env_head, char *env_str)
{
	t_env	*curr;

	curr = env_head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_env_node(env_str);
	if (curr->next == NULL)
		printf("allocate error\n");
}

void	set_env_list(t_env *env_head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		env_add(env_head, envp[i]);
		++i;
	}
}

t_env	*set_shell_env_list(char **envp)
{
	t_env *env_head;

	env_head = malloc(sizeof(t_env));
	if (env_head == NULL)
		return (NULL);
	set_env_list(env_head, envp);
	print_env_list(env_head);
	return (env_head);
}