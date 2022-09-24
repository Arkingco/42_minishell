/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 16:17:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "env.h"

t_env	*set_shell_env_list(char **envp)
{
	t_env *env_head;

	env_head = ft_safe_malloc(sizeof(t_env));
	env_head->str = NULL;
	env_head->key = NULL;
	env_head->value = NULL;
	env_head->next = NULL;
	set_env_list(env_head, envp);
	return (env_head);
}
