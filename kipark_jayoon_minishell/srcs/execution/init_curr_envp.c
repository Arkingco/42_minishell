/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:26:17 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 17:54:51 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static size_t	count_env(t_env *l_env)
{
	size_t	num_env;

	num_env = 0;
	while (l_env)
	{
		num_env++;
		l_env = l_env->next;
	}
	return (num_env);
}

static void	put_in_str_in_curr_envp(char **curr_envp, t_env *l_env)
{
	size_t	i;

	i = 0;
	while (l_env)
	{
		curr_envp[i] = l_env->str;
		i++;
		l_env = l_env->next;
	}
	curr_envp[i] = NULL;
}

char	**init_curr_envp(t_env *l_env)
{
	char	**curr_envp;
	size_t	num_env;

	num_env = 0;
	num_env = count_env(l_env);
	curr_envp = ft_safe_malloc(sizeof(char *) * (num_env + 1));
	put_in_str_in_curr_envp(curr_envp, l_env);
	return (curr_envp);
}
