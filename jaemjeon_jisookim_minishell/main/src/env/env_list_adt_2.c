/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:57:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:25:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envlst	*ft_getenv_lst(t_envlst *env, char *key)
{
	t_envlst	*lst;

	lst = env;
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

	envlst = env;
	while (envlst != NULL)
	{
		if (ft_strncmp(envlst->key, key, INT_MAX) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

int	ft_delenv(t_envlst **env, char *key)
{
	t_envlst	*lst_cur;
	t_envlst	*lst_prev;
	t_envlst	*lst_new_first;

	lst_cur = *env;
	if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
	{
		lst_new_first = lst_cur->next;
		ft_free_envlst(lst_cur);
		*env = lst_new_first;
		return (TRUE);
	}
	while (lst_cur->next != NULL)
	{
		lst_prev = lst_cur;
		lst_cur = lst_cur->next;
		if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
		{
			lst_prev->next = lst_cur->next;
			ft_free_envlst(lst_cur);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	ft_addenv_str(t_envlst *env, char *str_envp)
{
	const char	*p_del = ft_strchr(str_envp, '=');
	char		*key;
	char		*value;

	key = ft_substr(str_envp, 0, p_del - str_envp);
	value = ft_substr(str_envp, p_del -str_envp + 1, \
						ft_strlen(str_envp) - ft_strlen(key) - 1);
	if (key == NULL || value == NULL)
		ft_error(1, "malloc failed in ft_substr in ft_addenv_str");
	ft_addenv(env, key, value);
	free(key);
	free(value);
}
