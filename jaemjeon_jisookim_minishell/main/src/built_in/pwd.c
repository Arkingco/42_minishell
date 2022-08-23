/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:28:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:35:30 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_envlst *env)
{
	char	*pwd_value;

	pwd_value = ft_getenv(env, "PWD");
	if (pwd_value == NULL)
		return ;
	printf("%s\n", pwd_value);
}
