/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:33:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 22:08:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
quote로 둘러쌓인 토큰의 quote를 지움.
*/
void	quote_remove(t_token **token_lst)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if (cur_token->type & QUOTE)
		{
			ft_memmove(cur_token->string_value, cur_token->string_value + 1, \
										ft_strlen(cur_token->string_value));
			cur_token->string_value[ft_strlen(cur_token->string_value) - 1]\
																		 = '\0';
		}
		cur_token = cur_token->next;
	}
}

void	remove_trash_token(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*head_token;
	t_token	*to_del_token;

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & EXPANDER) && \
			ft_strlen(cur_token->string_value) == 0)
		{
			if (cur_token->prev == NULL)
				head_token = cur_token->next;
			to_del_token = cur_token;
			ft_deltoken(&to_del_token);
		}
		cur_token = cur_token->next;
	}
	*token_lst = head_token;
}
