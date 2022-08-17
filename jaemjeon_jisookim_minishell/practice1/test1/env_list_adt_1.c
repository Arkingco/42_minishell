/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 03:55:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/08 01:06:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_lstadd_back(t_envlst **lst, t_envlst *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		(ft_env_lstlast(*lst))->next = new;
}

int	ft_env_lstsize(t_envlst *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_envlst	*ft_env_lstnew(char *key, char *value)
{
	t_envlst	*node;

	node = (t_envlst *)malloc(sizeof(t_envlst));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
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

t_envlst	*ft_env_lstdelone(t_envlst *lst, char *key)
{
	t_envlst	*new_first_node;
	t_envlst	*prev_node;
	t_envlst	*next_node;

	new_first_node = lst;
	prev_node = NULL;
	while (lst != NULL)
	{
		if (ft_strncmp(key, lst->key, INT_MAX) == 0)
		{
			next_node = lst->next;
			if (lst->key != NULL)
				free(lst->key);
			if (lst->value != NULL)
				free(lst->value);
			free(lst);
			if (prev_node == NULL)
				new_first_node = next_node;
			else
				prev_node->next = next_node;
			break ;
		}
		prev_node = lst;
		lst = lst->next;
	}
	return (new_first_node);
}

t_envlst	*ft_env_lstdup(t_envlst *lst)
{
	t_envlst	*new_lst;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_env_lstadd_back(&new_lst, ft_env_lstnew(lst->key, lst->value));
		lst = lst->next;
	}
	return (new_lst);
}

void	ft_env_lstclear(t_envlst *lst)
{
	while (lst != NULL)
		lst = ft_env_lstdelone(lst, lst->key);
}

char	*ft_get_env_value(char *key)
{
	t_envlst	*envlst;

	envlst = getset_info(GET, e_envlst, NULL);
	while (envlst != NULL)
	{
		if (ft_strncmp(envlst->key, key, INT_MAX))
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}
