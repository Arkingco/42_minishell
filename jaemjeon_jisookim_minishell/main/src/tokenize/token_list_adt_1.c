/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_adt_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:07:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/30 16:51:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void		ft_token_lstadd_back(t_token **lst, t_token *new)
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

int			ft_token_lstsize(t_token *lst)
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

t_token		*ft_addtoken(t_token **lst, unsigned int type, char *string_value)
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

void		ft_free_token(t_token *lst)
{
	free(lst->string_value);
	lst->string_value = NULL;
	free(lst);
}

void		ft_free_tokenlst(t_token *lst)
{
	t_token	*next_token;

	while (1)
	{
		next_token = lst->next;
		ft_free_token(lst);
		lst = next_token;
		if (lst == NULL)
			return ;
	}
}

t_token		*ft_token_lstlast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
