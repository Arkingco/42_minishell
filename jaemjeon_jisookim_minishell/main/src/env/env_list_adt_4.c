/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:26:22 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 20:02:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_has_env(t_envlst *env, char *key)
{
	if (ft_getenv_lst(env, key) != NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_setenv(t_envlst *env, char *key, char *value, int has_value)
{
	t_envlst	*envlst_toset;

	envlst_toset = ft_getenv_lst(env, key);
	if (envlst_toset == NULL)
		ft_addenv(&env, key, value, has_value);
	else
	{
		if (has_value == FALSE && envlst_toset->has_value == TRUE)
			return ;
		free(envlst_toset->value);
		envlst_toset->value = 0;
		envlst_toset->value = ft_strdup(value);
		if (envlst_toset->value == NULL)
			ft_error_exit(1, "minishell: exit due to malloc failed");
		envlst_toset->has_value = has_value;
	}
}

t_envlst	*ft_getenv_lst(t_envlst *env, char *key)
{
	t_envlst	*lst;

	lst = ft_env_lst_first(env);
	while (lst != NULL)
	{
		if (ft_strncmp(lst->key, key, INT_MAX) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char	*ft_getenv(t_envlst *env, char *key)
{
	t_envlst	*envlst;

	envlst = ft_env_lst_first(env);
	while (envlst != NULL)
	{
		if (ft_strncmp(envlst->key, key, INT_MAX) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

t_envlst	*get_env_new_head(t_envlst *env)
{
	if (env->prev == NULL && env->next == NULL)
		return (NULL);
	else if (env->prev == NULL)
		return (env->next);
	else
		return (ft_env_lst_first(env));
}
