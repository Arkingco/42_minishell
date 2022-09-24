/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_adt_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:07:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 15:36:35 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_token_lstadd_back(t_token **lst, t_token *new)
{
	if (lst == NULL)
		ft_error_exit(1, "input para error in ft_token_lstadd_back");
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->prev = ft_token_lstlast(*lst);
		new->prev->next = new;
		new->next = NULL;
	}
}

int	ft_token_lstsize(t_token *lst)
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

t_token	*ft_addtoken(t_token **lst, unsigned int type, char *string_value)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in ft_addtoken");
	token->string_value = ft_strdup(string_value);
	token->type = type;
	if (token->string_value == NULL)
		ft_error_exit(1, "malloc failed in ft_strdup in ft_addtoken");
	ft_token_lstadd_back(lst, token);
	return (token);
}

t_token	*ft_token_lstlast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
