/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:45:55 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 15:50:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_token_list(t_token *token_head)
{
	t_token	*this_token;

	this_token = token_head->next;
	while (this_token)
	{
		printf("%s   length:%zu  token_tpye: %d\n", \
				this_token->str, ft_strlen(this_token->str), this_token->type);
		this_token = this_token->next;
	}
}

void	init_token_dummy_node(t_token *new_token)
{
	new_token->next = NULL;
	new_token->str = NULL;
	new_token->type = T_NULL;
}

void	token_free(t_token *token)
{
	t_token	*this_token;
	t_token	*next;

	this_token = token;
	while (this_token)
	{
		next = this_token->next;
		if (this_token->str != NULL)
			free(this_token->str);
		free(this_token);
		this_token = next;
	}
	return ;
}

t_token	*new_token_node(t_token_type token_type, char *token_str)
{
	t_token	*new_token;

	new_token = ft_safe_malloc(sizeof(t_token));
	init_token_dummy_node(new_token);
	new_token->type = token_type;
	new_token->str = token_str;
	return (new_token);
}

void	token_add(t_token *token_head, t_token_type token_type, \
															char *token_str)
{
	t_token	*curr;

	curr = token_head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_token_node(token_type, token_str);
	if (curr->next == NULL)
		ft_check_error(E_MALLOC, (ssize_t)curr->next);
}
