/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_adt_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:07:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/26 18:10:22 by jaemjeon         ###   ########.fr       */
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
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_insert_token(t_token *prev_to_insert, t_token *to_insert)
{
	t_token	*next_of_inserted;

	if (to_insert == NULL)
		return ;
	next_of_inserted = prev_to_insert->next;
	prev_to_insert->next = to_insert;
	to_insert->prev = prev_to_insert;
	while (to_insert->next != NULL)
		to_insert = to_insert->next;
	to_insert->next = next_of_inserted;
	if (next_of_inserted != NULL)
		next_of_inserted->prev = to_insert;
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
