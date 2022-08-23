
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:18:15 by kipark            #+#    #+#             */
/*   Updated: 2022/08/23 11:37:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "stdlib.h"
#include "libft.h"
#include <stdio.h> 

char *find_env_value(char *env_key)
{
	return (ft_strdup("hi we are minis sheel"));
}

int	is_env_key_word(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

static int	get_env_key_size(char *env_key)
{
	int	i;

	i = 0;
	while (is_env_key_word(env_key[i]))
		++i;
	return (i);
}
void	meet_dollar_and_work(char *str)
{
	int env_key_size;
	char *env_key;
	char *env_value;

	env_key_size = get_env_key_size(str);
	env_key = ft_substr(str, 0, env_key_size);
	env_value = find_env_value(env_key);
}

void	expand_this_token(t_token *this_token)
{
	int	i;

	i = 0;
	while (this_token->str[i] != '\0')
	{
		printf("%c\n", this_token->str[i]);
		// 이미 WORD 단위로 나눠져 있기 때문에 확장할 때 ifs 와 metaCarater를 체크할 필요 없다.
		// 체크 할 부분은 str[i] == 싱글 쿼터로 되어있나
		if (this_token->str[i] == M_SINGLE_QUOTE)
		{
			while (this_token->str[i + 1] != M_SINGLE_QUOTE)
				++i;
			++i;
		}
		// 아니면 WORD or DOUBLE_QOUTE 로 되어있나
		else
		{
			if (this_token->str[i] == M_DOLLAR_EXPAND)
				meet_dollar_and_work(this_token->str + i + 1);
		}
		++i;
	}
}

void	token_traverse(t_token *token_head)
{
	t_token *this_token;

	this_token = token_head->next;
	while (1)
	{
		if (this_token->next == NULL)
			break ;
		if (this_token->type == T_WORD)
		{
			printf("%s %d \n", this_token->str, this_token->type);
			expand_this_token(this_token);
		}
		this_token = this_token->next;
	}
}

void	expand_token_main(t_token *token_head)
{
	// 1. 토큰을 순회해서 해당하는 토믄 타입이 word인지 확인하다
	// 2. 토큰 타입이 word라면 해당하는 토큰에 확장 $가 있는지 확인한다
	//	2.1 토큰 타입은 총 WORD, SINGLE_QOUTE, DOUBLE_QOUTE가 있다 체크는 더블 쿼트 .워드 만하는걸로하자!
	// 3. 확장 문구인 $가 있다면 $ 옆에 있는 문자를 확인하여 확장해야하는 값의 키를 가져온다.
	// 	3.1 확장 키로 올 수 있는 값은 영어 소문자, 대문자, 숫자, 언더바 말고 없다고 한다 이 외에 다른 조건이 오면 무조건 틀림
	// 4. 키 값을 가져오고 타입에 따라서 확장해준다.
	//  4.1 제일 문제부분 이부분을 처리 할려면 문제가 많다..
	token_traverse(token_head);
}