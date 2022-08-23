/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_adt_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:23:07 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/23 23:45:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_token	*ft_addtoken(t_token **token, int type, int redirect_type, char *word_value)
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
	ft_token_lstadd_back(token, node);
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

void	ft_deltoken(t_token **p_to_del)
{
	t_token	*prev_token;
	t_token	*to_del;

	if (p_to_del == NULL || *p_to_del == NULL)
		return ;
	to_del = *p_to_del;
	prev_token = to_del->prev;
	prev_token->next = to_del->next;
	if (to_del->next != NULL)
		to_del->next->prev = prev_token;
	free(to_del->word_value);
	free(to_del);
}

void	ft_jointoken_with_next(t_token **p_first_token)
{
	t_token	*first_token;
	t_token	*second_token;
	char	*first_word_value;

	first_token = *p_first_token;
	second_token = first_token->next;
	if (first_token->type == E_REDIRECT)
	{
		first_token->word_value = ft_strdup(second_token->word_value);
		ft_deltoken(&second_token);
	}
	else if (first_token->type == E_WORD)
	{
		first_word_value = first_token->word_value;
		first_token->word_value = \
			ft_strjoin(first_token->word_value, second_token->word_value);
		free(first_word_value);
		ft_deltoken(&second_token);
	}
	else
		ft_putendl_fd("error in ft_jointoken_with_next\n", 2);
}

void	ft_jointoken_with_prev(t_token **p_second_token)
{
	t_token	*second_token;
	t_token	*first_token;
	char	*second_word_value;

	second_token = *p_second_token;
	first_token = second_token->prev;
	if (first_token->type == E_REDIRECT)
	{
		second_token->type = first_token->type;
		second_token->redirect_type = first_token->redirect_type;
		ft_deltoken(&first_token);
	}
	else if (first_token->type == E_WORD)
	{
		second_word_value = second_token->word_value;
		second_token->word_value = \
			ft_strjoin(first_token->word_value, second_token->word_value);
		free(second_word_value);
		ft_deltoken(&first_token);
	}
}
