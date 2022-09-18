/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:57:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/12 03:08:58 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	ft_delenv(t_envlst **env, char *key)
{
	t_envlst	*lst_cur;
	t_envlst	*lst_new_first;

	lst_cur = ft_env_lst_first(*env);
	if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
	{
		lst_new_first = lst_cur->next;
		lst_new_first->prev = NULL;
		ft_free_envlst(lst_cur);
		*env = lst_new_first;
		return (TRUE);
	}
	while (lst_cur->next != NULL)
	{
		lst_cur = lst_cur->next;
		if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
		{
			lst_cur->prev->next = lst_cur->next;
			lst_cur->next->prev = lst_cur->prev;
			ft_free_envlst(lst_cur);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	ft_addenv_str(t_envlst **env, char *str_envp)
{
	const char	*p_del = ft_strchr(str_envp, '=');
	char		*key;
	char		*value;

	if (p_del == NULL)
	{
		ft_addenv(env, str_envp, "", FALSE);
		return ;
	}
	key = ft_substr(str_envp, 0, p_del - str_envp);
	// if (*(p_del + 1) == '\0' || ft_is_ifs(p_del + 1))
	// 	value = ft_strdup("");
	if (*(p_del + 1) == '\0')
		value = ft_strdup("");
	else
		value = ft_substr(str_envp, p_del - str_envp + 1,
						  ft_strlen(str_envp) - ft_strlen(key) - 1);
	if (key == NULL || value == NULL)
		ft_error_exit(1, "malloc failed in ft_substr or ft_strdup in ft_addenv_str");
	ft_addenv(env, key, value, TRUE);
	free(key);
	free(value);
}

t_envlst	*ft_env_lst_first(t_envlst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}
