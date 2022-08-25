/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:39:33 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/25 12:50:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_env(t_envlst *env)
{
	while (env != NULL)
	{
		//printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}