/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:09:42 by kipark            #+#    #+#             */
/*   Updated: 2022/08/30 16:37:07 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

static void	remove_quote_in_quotes_str(int *i, int *j, char *str, char quote)
{
	
	++(*i);
	while (str[*i] != quote)
	{
		str[*j] = str[*i];
		++(*j);
		++(*i);
	}
	++(*i);
}

static void	remove_quote_word_token(t_token *this_token)
{
	char *str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = this_token->str;
	while(str[i] != '\0')
	{
		if (str[i] == M_SINGLE_QUOTE)
			remove_quote_in_quotes_str(&i, &j, str, M_SINGLE_QUOTE);
		else if (str[i] == M_DOUBLE_QUOTE)
			remove_quote_in_quotes_str(&i, &j, str, M_DOUBLE_QUOTE);
		else
		{
			str[j] = str[i];
			++j;
			++i;
		}
	}
	str[j] = '\0';
}

void	remove_quote(t_token *token_head)
{
	t_token *this_token;

	this_token = token_head;
	while (this_token)
	{
		if (this_token->type == T_WORD)
			remove_quote_word_token(this_token);
		this_token = this_token->next;
	}
}
