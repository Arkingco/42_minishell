/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:45:55 by kipark            #+#    #+#             */
/*   Updated: 2022/08/22 15:33:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	print_token_list(t_token *token_head)
{
	t_token *this_token;

	this_token = token_head->next;
	while (1)
	{
		if (this_token->next == NULL)
			break ;
		printf("token_str: %s   token_str_length:%zu  token_tpye: %d\n", this_token->str, ft_strlen(this_token->str), this_token->type);
		this_token = this_token->next;
	}
}

void	init_token_dummy_node(t_token *token_head)
{
	token_head->next = NULL;
	token_head->str = NULL;
	token_head->type = T_NULL;
}

t_token *new_token_node(t_token_type token_type, char *token_str)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
		printf("Token ERROR");
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
}
