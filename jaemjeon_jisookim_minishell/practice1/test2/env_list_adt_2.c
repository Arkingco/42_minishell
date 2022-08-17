/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:57:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/17 04:12:54 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global g_global;

// t_envlst	*ft_env_lstdup(t_envlst *lst)
// {
// 	t_envlst	*new_lst;

// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst != NULL)
// 	{
// 		ft_env_lstadd_back(&new_lst, ft_env_lstnew(lst->key, lst->value));
// 		lst = lst->next;
// 	}
// 	return (new_lst);
// }

t_envlst	*ft_getenv_lst(char *key)
{
	t_envlst	*lst;

	lst = g_global.lst_env;
	while (lst != NULL)
	{
		if (ft_strncmp(lst->key, key, INT_MAX) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char	*ft_getenv(char *key)
{
	t_envlst	*envlst;

	envlst = g_global.lst_env;
	while (envlst != NULL)
	{
		if (ft_strncmp(envlst->key, key, INT_MAX))
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

int	ft_delenv(char *key)
{
	t_envlst	*lst_cur;
	t_envlst	*lst_prev;
	t_envlst	*lst_tmp;

	if (ft_strncmp(g_global.lst_env->key, key, INT_MAX) == 0)
	{
		lst_tmp = g_global.lst_env->next;
		ft_free_envlst(g_global.lst_env);
		g_global.lst_env = lst_tmp;
		return (TRUE);
	}
	lst_prev = g_global.lst_env;
	lst_cur = lst_prev->next;
	while (lst_cur != NULL)
	{
		if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
		{
			lst_prev->next = lst_cur->next;
			ft_free_envlst(lst_cur);
		}
		lst_prev = lst_cur;
		lst_cur = lst_cur->next;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_addenv_str(char *str_envp)
{
	const char	*p_del = ft_strchr(str_envp, '=');
	const char	*p_null = ft_memchr(str_envp, '\0', INT_MAX);
	char		*key;
	char		*value;

	key = ft_substr(str_envp, 0, p_del - str_envp);
	value = ft_substr(str_envp, p_del -str_envp + 1, \
						ft_strlen(str_envp) - ft_strlen(key) - 1);
	if (key == NULL || value == NULL)
		ft_error(1, "malloc failed in ft_substr in ft_addenv_str");
	ft_addenv(key, value);
	free(key);
	free(value);
}
