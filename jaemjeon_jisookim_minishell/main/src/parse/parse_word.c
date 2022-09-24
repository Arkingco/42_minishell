/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:23:16 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 14:27:10 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
word와 quote의 경우, 처음 토큰이 따로 되어있었으나 결국은 결과적으로 붙어있는 상태라면
(확장이후에 안붙어 있을 수 있으니 확장후를 봐야함) left_join & right_join 양쪽이 합치된다면 토큰을 합쳐줌
*/
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

/*
일단 word이고 quote밖에 있고 공백을 가지고 있다? -> 확장되서어 공백이 생긴것이므로 word_split을
해야하는 토큰으로 판단.
*/
int	is_to_word_split(t_token *token)
{
	return ((token->type & WORD) && !(token->type & QUOTE) && \
		ft_has_ifs(token->string_value));
}

/*
토큰리스트를 쭉 돌면서 word_split해야하는 토큰들을 모두 토큰split해줌
*/
void	word_split(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*to_del_token;
	t_token	*splited_lst;
	t_token	*head_token; // 매개변수를 통해 리스트의 맨 처음포인터를 가르켜줄것임.

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if (is_to_word_split(cur_token)) // word_split할 토큰을 찾음
		{
			splited_lst = __word_split(cur_token); // split된 연결리스트 반환
			ft_insert_token(cur_token, splited_lst); // 현재다음으로 연결해주고,
			if (cur_token->prev == NULL) // 만약에 현재가 맨처음것이라면
				head_token = cur_token->next; // head_token을 다음것으로 바꿔줌.
			to_del_token = cur_token; // 이미 split해서 반영했으므로 현재것은 지워줌
			cur_token = cur_token->next;
			ft_deltoken(&to_del_token);
		}
		else
			cur_token = cur_token->next;
	}
	*token_lst = head_token; // 맨처음 연결리스트 반영
}
