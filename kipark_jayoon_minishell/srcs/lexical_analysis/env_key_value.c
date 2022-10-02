/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:18:31 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 16:42:58 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "exit_status.h"

char	*get_env_key(char *str)
{
	char	*env_key;

	env_key = ft_safe_substr(str, 0, get_env_key_size(str));
	return (env_key);
}

char	*get_env_value(t_env *env_head, char *env_key)
{
	t_env	*env_list;

	env_list = env_head->next;
	if (*env_key == '?')
		return (ft_strdup(ft_itoa(g_exit_status)));
	while (env_list)
	{
		if (ft_strncmp(env_key, env_list->key, ft_strlen(env_key) + 1) == 0)
		{
			if (env_list->value == NULL)
				return (ft_strdup(""));
			return (ft_safe_strdup(env_list->value));
		}
		env_list = env_list->next;
	}
	return (ft_safe_strdup(""));
}