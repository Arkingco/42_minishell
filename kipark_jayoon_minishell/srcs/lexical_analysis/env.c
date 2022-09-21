/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/09/20 21:16:52 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "env.h"

t_env	*set_shell_env_list(char **envp)
{
	t_env *env_head;

	env_head = malloc(sizeof(t_env));
	if (env_head == NULL)
		return (NULL);
	env_head->str = NULL;
	env_head->next = NULL;
	set_env_list(env_head, envp);
	return (env_head);
}
