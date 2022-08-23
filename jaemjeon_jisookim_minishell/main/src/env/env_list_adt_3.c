/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:24:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:30:36 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_has_env(t_envlst *env, char *key)
{
	if (ft_getenv_lst(env, key) != NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_setenv(t_envlst *env, char *key, char *value)
{
	t_envlst	*envlst_toset;

	envlst_toset = ft_getenv_lst(env, key);
	free(envlst_toset->value);
	envlst_toset->value = ft_strdup(value);
	if (envlst_toset->value == NULL)
		ft_error(1, "malloc failed in ft_strdup of ft_setenv");
}

char	**ft_envlst_to_envp(t_envlst *env)
{
	char		**envp;
	char		*envp_argv;
	int			index;
	t_envlst	*envlst;

	envlst = env;
	envp = (char **)ft_calloc(sizeof(char *), ft_env_lstsize(envlst) + 1);
	index = 0;
	while (envlst != NULL)
	{
		envp_argv = ft_strjoin(envlst->key, envlst->value);
		envp[index] = envp_argv;
		index++;
	}
	return (envp);
}
