/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:35:59 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:34:53 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_envlst *env)
{
	t_envlst	*envlst;

	envlst = env;
	while (envlst != NULL)
	{
		printf("%s=%s\n",envlst->key, envlst->value);
		envlst = envlst->next;
	}
}
