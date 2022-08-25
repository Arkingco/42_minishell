/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_adt_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:13:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/25 12:23:09 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_deltoken(t_token **lst)
{
	t_token	*to_free_token;
	t_token	*prev_token;
	t_token	*next_token;

	to_free_token = *lst;
	prev_token = to_free_token->prev;
	next_token = to_free_token->next;
	if (prev_token == NULL)
	{
		ft_free_tokenlst(to_free_token);
		*lst = next_token;
	}
	else if (next_token == NULL)
	{
		ft_free_tokenlst(to_free_token);
		prev_token->next = NULL;
	}
	else
	{
		ft_free_tokenlst(to_free_token);
		prev_token->next = next_token;
		next_token->prev = prev_token;
	}
}

t_token		*ft_token_lst_first(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}
