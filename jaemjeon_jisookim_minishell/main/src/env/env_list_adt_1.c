/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 03:55:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/12 02:57:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env_lstadd_back(t_envlst **lst, t_envlst *new)
{
	if (lst == NULL)
		ft_error_exit(1, "para input error in ft_env_lstadd_back");
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = ft_env_lstlast(*lst);
		new->prev->next = new;
	}
}

int	ft_env_lstsize(t_envlst *lst)
{
	int	size;

	size = 0;
	lst = ft_env_lst_first(lst);
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_envlst	*ft_addenv(t_envlst **env, char *key, char *value, int has_value)
{
	t_envlst	*node;

	node = (t_envlst *)ft_calloc(1, sizeof(t_envlst));
	if (node == NULL)
		ft_error_exit(1, "failed in malloc env_node");
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->has_value = has_value;
	node->next = NULL;
	if (node->key == NULL || node->value == NULL)
		ft_error_exit(1, "failed in malloc env_key or env_value");
	ft_env_lstadd_back(env, node);
	return (node);
}

t_envlst	*ft_env_lstlast(t_envlst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_free_envlst(t_envlst *lst)
{
	free(lst->key);
	free(lst->value);
	free(lst);
}
