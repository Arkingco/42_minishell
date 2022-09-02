/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/08/30 15:42:35 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"libft.h"
#include"env.h"

t_env	*set_shell_env_list(char **envp)
{
	t_env *env_head;

	env_head = malloc(sizeof(t_env));
	if (env_head == NULL)
		return (NULL);
	set_env_list(env_head, envp);
	return (env_head);
}