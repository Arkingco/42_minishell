/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/14 03:26:39 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_cmd *cmd, t_working_info *info)
{
	t_envlst	*env;

	env = info->env;
	while (env != NULL)
	{
		if (env->has_value == TRUE)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}