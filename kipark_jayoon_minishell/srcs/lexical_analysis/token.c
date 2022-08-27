/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:45:55 by kipark            #+#    #+#             */
/*   Updated: 2022/08/27 15:45:38 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_token_list(t_token *token_head)
{
	t_token *this_token;

	this_token = token_head->next;
	while (this_token)
	{
		printf("\n%s   length:%zu  token_tpye: %d\n", \
				this_token->str, ft_strlen(this_token->str), this_token->type);
		this_token = this_token->next;
	}
}

void	init_token_dummy_node(t_token *token_head)
{
	token_head->next = NULL;
	token_head->str = NULL;
	token_head->type = T_NULL;
}

void	token_free(t_token *token)
{
	if (token->str != NULL)
		free(token->str);
	if (token)
		free(token);
	return ;
}

t_token *new_token_node(t_token_type token_type, char *token_str)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
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
		printf("allocate error\n");
}
