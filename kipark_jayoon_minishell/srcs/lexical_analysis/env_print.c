/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:08:19 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 12:34:17 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int is_env_value_null(char env_word)
{
	if (env_word == '\0')
		return (1);
	return (0);
}

void	print_env_list(t_env *env_head)
{
	t_env *env_list;

	env_list = env_head->next;
	while (env_list)
	{
		if (!is_env_value_null(*(env_list->value)))
			printf("%s=%s\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
}
