/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:49:42 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/07 16:28:52 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_env(void)
{
	t_envlst	*envlst;

	envlst = (t_envlst *)getset_info(GET, e_envlst, NULL);
	while (envlst != NULL)
	{
		printf("%s=%s\n", envlst->key, envlst->value);
		envlst = envlst->next;
	}
}
