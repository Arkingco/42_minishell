/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:35:59 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 15:46:40 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	env(void)
{
	t_envlst	*envlst;

	envlst = g_global.lst_env;
	while (envlst != NULL)
	{
		printf("%s=%s\n",envlst->key, envlst->value);
		envlst = envlst->next;
	}
}
