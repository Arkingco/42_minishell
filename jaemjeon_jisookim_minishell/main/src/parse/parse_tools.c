/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:16:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 14:17:54 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
__get_envvlaue함수에서 envkey에 해당하는 만큼 포인터를 옮길때 사용함.
*/
void	__skip_envkey(char **pointer)
{
	while (**pointer != '$' && **pointer != '\0' && **pointer != '\"' && \
		**pointer != '\'' && !ft_is_ifs(*pointer))
		(*pointer)++;
}

/*
expand_env_withdollar에서 호출하는 함수로, 현재토큰의 마지막문자가 $이고 다음 토큰이 quote이면서
붙어있는 상태 (ex : $"HELLO") 인 경우에 앞의 $를 지워야하는데 그 상태인지 판단하는 함수
*/
int	__is_to_remove_dollar(t_token *cur_token, char *context)
{
	if ((*context == '\0') && (cur_token->next != NULL) && \
			(cur_token->type & RIGHT_JOIN) && (cur_token->next->type & QUOTE))
		return (TRUE);
	else
		return (FALSE);
}

/*
cpy_none_expander함수에서 호출하는 함수로, 다음 ifs, 널문자, $문자까지 포인터를 옮겨줌
*/
void	__skip_only_quote_and_letter(char **pointer)
{
	while (**pointer != '\0' && **pointer != '$' && \
			ft_is_ifs(*pointer) == FALSE)
		(*pointer)++;
}

/*
word_split함수에서 내부적으로 실행하는 함수.
word_split함수는 token_lst를 쭉 돌면서 split하는 함수라면 __word_split은 매개변수로 받은
token만을 split히여 그 split된 token_lst를 반환함. 하지만 매개변수로 받은 토큰을 지우지는 않음.
*/
t_token	*__word_split(t_token *token)
{
	char	*string_value;
	t_token	*splited_lst;
	t_token	*new_token;

	splited_lst = NULL;
	string_value = token->string_value;
	if (is_ifs_word(string_value))
		splited_lst = \
			ft_make_newtoken(token->type & ~(LEFT_JOIN | RIGHT_JOIN), ""); // 만약 ifs만으로 이루어진 토큰인 경우..
	else
	{
		while (*string_value != '\0')
		{
			// 토큰의 string_value를 쭉 훑으면서 ifs를 건너뛰고 하나씩 토큰화함. 물론 join_flag도 관리해줌
			new_token = ft_strtok_token(token->type, &string_value);
			if (new_token == NULL) // 더이상 토큰화할게 없음.
				break;
			ft_token_lstadd_back(&splited_lst, new_token);
		}
	}
	return (splited_lst); // split된 토큰 연결리스트 반환.
}
