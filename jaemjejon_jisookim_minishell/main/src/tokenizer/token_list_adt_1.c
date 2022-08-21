/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_adt_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:23:07 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/21 19:24:48 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/variables/var_base_struct.h"

extern t_global	g_global;

void	ft_token_lstadd_back(t_token **lst, t_token *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		(ft_token_lstlast(*lst))->next = new;
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

t_token	*ft_addtoken(int type, int redirect_type, char *word_value)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node == NULL)
		ft_error(1, "failed in malloc token_lst");
	node->type = type;
	node->redirect_type = redirect_type;
	if (word_value != NULL)
		node->word_value = ft_strdup(word_value);
	node->next = NULL;
	if (node->word_value == NULL)
		ft_error(1, "failed in malloc token_word_value");
	ft_token_lstadd_back(&(g_global.lst_token), node);
	return (node);
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

void	ft_free_token(t_token *lst)
{
	free(lst->word_value);
	free(lst);
}

t_token	*ft_tokendup(t_token *token)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error(1, "malloc failed in malloc new_token");
	new_token->type = token->type;
	new_token->redirect_type = token->redirect_type;
	new_token->word_value = ft_strdup(token->word_value);
	if (new_token->word_value == NULL)
		ft_error(1, "malloc failed in malloc ft_strdup in ft_tokendup");
	new_token->next = NULL;
	return (new_token);
}