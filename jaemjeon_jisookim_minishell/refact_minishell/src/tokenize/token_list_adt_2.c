/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_adt_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:13:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/27 15:58:56 by jaemjeon         ###   ########.fr       */
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
	ft_free_tokenlst(to_free_token);
	if (prev_token == NULL && prev_token == NULL)
		*lst = NULL;
	else if (prev_token == NULL)
	{
		*lst = next_token;
		(*lst)->prev = NULL;
	}
	else if (next_token == NULL)
		prev_token->next = NULL;
	else
	{
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

t_token	*ft_make_newtoken(unsigned int type, char *string_value)
{
	t_token	*new_token;

	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in ft_make_newtoken");
	new_token->type = type;
	new_token->string_value = ft_strdup(string_value);
	if (new_token->string_value == NULL)
		ft_error_exit(1, "malloc failed in ft_strdup in ft_make_newtoken");
	return (new_token);
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