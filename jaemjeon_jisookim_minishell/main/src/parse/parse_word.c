/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:23:16 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 19:53:33 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	word_join(t_token **token_lst)
{
	t_token	*cur_token;
	char	*joined_string;

	cur_token = *token_lst;
	while (cur_token != NULL && cur_token->next != NULL)
	{
		if (cur_token->type & RIGHT_JOIN && cur_token->next->type & LEFT_JOIN)
		{
			joined_string = \
			ft_strjoin(cur_token->string_value, cur_token->next->string_value);
			free(cur_token->next->string_value);
			cur_token->next->string_value = joined_string;
			cur_token = cur_token->next;
			if (cur_token->prev->prev == NULL)
				*token_lst = cur_token;
			ft_deltoken(&(cur_token->prev));
		}
		else
			cur_token = cur_token->next;
	}
}

int	is_to_word_split(t_token *token)
{
	return ((token->type & WORD) && !(token->type & QUOTE) && \
		ft_has_ifs(token->string_value));
}

void	word_split(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*to_del_token;
	t_token	*splited_lst;
	t_token	*head_token;

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if (is_to_word_split(cur_token))
		{
			splited_lst = __word_split(cur_token);
			ft_insert_token(cur_token, splited_lst);
			if (cur_token->prev == NULL)
				head_token = cur_token->next;
			to_del_token = cur_token;
			cur_token = cur_token->next;
			ft_deltoken(&to_del_token);
		}
		else
			cur_token = cur_token->next;
	}
	*token_lst = head_token;
}
