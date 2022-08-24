
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

char *get_env_value() // char *env_key 지워둠
{
	return (ft_strdup("[start]"));
}

int	is_env_key_word(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

// void	new_token_append(t_token *new_token, t_token next_token)
// {
	
// }


static int	get_env_key_size(char *env_key)
{
	int	i;

	i = 0;
	while (is_env_key_word(env_key[i]))
		++i;
	return (i);
}
char	*expand_and_join_words(char *str, int *i)
{
	int env_key_size;
	char *env_key;
	char *env_value;
	char *expand_str;
	char *after_str;

	env_key_size = get_env_key_size(str);
	env_key = ft_substr(str, 0, env_key_size);
	env_value = get_env_value();
	after_str = ft_substr(str, env_key_size, ft_strlen(str));
	*i = *i + ft_strlen(env_value) - 1;
	expand_str = ft_strjoin(env_value, after_str);
	free(env_value);
	free(env_key);
	free(after_str);
	return (expand_str);
}

void	expand_this_token(t_token *this_token)
{
	int	i;
	char *temp_str;
	char *before_str;
	char *after_str;

	i = 0;
	while (this_token->str[i] != '\0')
	{
		if (this_token->str[i] == M_SINGLE_QUOTE)
		{
			while (this_token->str[i + 1] != M_SINGLE_QUOTE)
				++i;
			++i;
		}
		else
		{
			if (this_token->str[i] == M_DOLLAR_EXPAND)
			{
				temp_str = this_token->str;
				before_str = ft_substr(this_token->str, 0, i);
				after_str = expand_and_join_words(this_token->str + i + 1, &i);
				this_token->str = ft_strjoin(before_str, after_str);
				free(temp_str);
				free(before_str);
				free(after_str);
			}
		}
		++i;
	}
	this_token->str = this_token->str;
	// new_token_append(this_token->str, this_token->next);

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
			expand_this_token(this_token);
			printf("%s\n", this_token->str);
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
	token_traverse(token_head);
}