/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:57:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 17:36:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_delenv(t_envlst **env, char *key)
{
	t_envlst	*lst_cur;
	t_envlst	*lst_new_first;

	lst_cur = ft_env_lst_first(*env);
	while (lst_cur != NULL)
	{
		if (ft_strncmp(lst_cur->key, key, INT_MAX) == 0)
		{
			lst_new_first = get_env_new_head(lst_cur);
			*env = lst_new_first;
			if (lst_cur->next != NULL)
				lst_cur->next->prev = lst_cur->prev;
			if (lst_cur->prev != NULL)
				lst_cur->prev->next = lst_cur->next;
			ft_free_envlst(lst_cur);
			return (TRUE);
		}
		lst_cur = lst_cur->next;
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
	if (*(p_del + 1) == '\0')
		value = ft_strdup("");
	else
		value = ft_substr(str_envp, p_del - str_envp + 1,
						  ft_strlen(str_envp) - ft_strlen(key) - 1);
	if (key == NULL || value == NULL)
		ft_error_exit(1, "malloc failed in ft_substr or \
										ft_strdup in ft_addenv_str");
	ft_addenv(env, key, value, TRUE);
	free_two_strings(key, value);
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
