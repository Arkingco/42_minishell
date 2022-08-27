/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:09:42 by kipark            #+#    #+#             */
/*   Updated: 2022/08/27 13:44:26 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

static void	quote_remove_in_quote(int *i, int *j, char *str, char quote)
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

static void	quote_remove_word_token(t_token *this_token)
{
	char *str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = this_token->str;
	while(str[i] != '\0')
	{
		if (str[i] == '\'')
			quote_remove_in_quote(&i, &j, str, M_SINGLE_QUOTE);
		else if (str[i] == '\"')
			quote_remove_in_quote(&i, &j, str, M_DOUBLE_QUOTE);
		else
		{
			str[j] = str[i];
			++j;
			++i;
		}
	}
	str[j] = '\0';
}

void	quote_rmove(t_token *token_head)
{
	t_token *this_token;

	this_token = token_head;
	while (this_token)
	{
		if (this_token->type == T_WORD)
			quote_remove_word_token(this_token);
		this_token = this_token->next;
	}
}
