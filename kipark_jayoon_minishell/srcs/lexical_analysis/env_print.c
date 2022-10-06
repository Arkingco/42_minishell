/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:08:19 by kipark            #+#    #+#             */
/*   Updated: 2022/10/06 10:46:18 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_env_list(t_env *env_head)
{
	t_env	*env_list;

	env_list = env_head->next;
	while (env_list)
	{
		if (env_list->value != NULL)
			ft_multi_putendl_fd(env_list->key, "=", env_list->value, 1);
		env_list = env_list->next;
	}
}
