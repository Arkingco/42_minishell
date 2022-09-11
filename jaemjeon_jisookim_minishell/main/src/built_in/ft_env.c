/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 03:18:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_cmd *cmd, t_envlst *env)
{
	while (env != NULL)
	{
		if (env->has_value == TRUE)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}