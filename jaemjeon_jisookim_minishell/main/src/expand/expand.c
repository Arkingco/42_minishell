/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:47:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/22 12:38:17 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expand_pidenv(t_token *token)
{
	char	*pid_suspect;

	pid_suspect = token->string_value;
	while (1)
	{
		pid_suspect = ft_strchr(pid_suspect, '$'); // $로 시작하는 주소로 이동
		if (pid_suspect == NULL) // $가 없었던 문자였으면 그냥 while문 탈출
			break ;
		if (ft_strncmp(pid_suspect, "$$", 2) != 0) // $뒤에 $가 연속으로 나온게 아닌경우
		{
			pid_suspect++; // 다음 칸으로 이동
			continue ;
		}
		else // $$가 나와서 pid로 확장을 해야하는 경우
		{
			pid_suspect[0] = '4';
			pid_suspect[1] = '2';
			token->type |= EXPANDED; // 그냥 지워진게 아니라 pid로 확장이 되었다는 맥락이니까 expanded flag도 박아줌
		}
	}
}

/*
$를 만났을때 확장하여 그 확장된 문자열을 반환해 주는 함수.
*/
char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*expanded_string;
	char	*env_key;

	cpy_start = *context; // 현재 읽고 있는 토큰의 문자열 문맥을 받아옴
	cpy_end = cpy_start + 1;
	if (__is_to_remove_dollar(token, cpy_end)) //  지워야하는 $인지 판단
		expanded_string = ft_strdup(""); // 지워야하는거면 $를 빈문자열 반환
	else
	{
		expanded_string = __get_envvalue(cpy_start, &cpy_end, env); // 확장하여 반환
		token->type |= EXPANDED; // 확장된 토큰이라는 flag설정
	}
	*context = cpy_end; // 다음 $를 찾아 가야하니까 지금까지 읽은곳 다음 칸으로 문맥변경
	return (expanded_string);
}

/*
none_expander즉 일반 영문자나 따움표같은 문자들(널, ifs, $, 리다이렉션문자만나면 멈춤)을 쭉 복사해서 반환함.
*/
void	*cpy_none_expander(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context;
	cpy_end = cpy_start;
	__skip_only_quote_and_letter(&cpy_end);
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start);
	*context = cpy_end;
	return (copied_string);
}

/*
현재토큰에서 확장을 해야하는 것들을 만나면 확장을 쭉해줌. 문자열덩어리, ifs덩어리, 확장된 덩어리들을
한 덩어리씩 모아서 계속 버퍼를 늘려주고 strlcat을 하여 늘려줌(strjoin을 계속하는 느낌)
*/
void	expand_env(t_token *token, t_envlst *env)
{
	char	*cpy_start;
	char	*result;
	char	*copied_string;
	char	*env_key;
	char	*env_value;

	cpy_start = token->string_value;
	result = ft_strdup(""); // 확장을 다한 문자열이 들어갈 공간
	while (*cpy_start != '\0')
	{
		if (*cpy_start == '$') // 확장가능성있는 문맥 발견
			copied_string = expand_env_withdollar(token, env, &cpy_start);
		else if (ft_is_ifs(cpy_start)) // ifs를 발견
			copied_string = cpy_ifs_string(&cpy_start);
		else // ifs도 아니고 확장가능성있는것도 아닌 일반 문자열또는 quote문자
			copied_string = cpy_none_expander(&cpy_start);
		result = raise_buffer(result, ft_strlen(copied_string)); // 확장된, 또는 복사해온 문자열길이만큼 버퍼를 키워줌.
		ft_strlcat(result, copied_string, \
							ft_strlen(result) + ft_strlen(copied_string) + 1); // 문자열 붙여줌
		free(copied_string);
	}
	free(token->string_value); // 확장된 문자열로 업데이트
	token->string_value = result;
}

int	is_heredoc_delimiter_token(t_token *token)
{
	while (token->prev && token->type & WORD && token->prev->type & WORD && \
													token->type & LEFT_JOIN)
		token = token->prev;
	if (token->prev && token->prev->type & HEREDOC)
		return (TRUE);
	else
		return (FALSE);
}

void	expander(t_token **tokne_lst, t_envlst *env)
{
	t_token	*cur_token;

	cur_token = *tokne_lst;
	while (cur_token != NULL)
	{
		if (is_heredoc_delimiter_token(cur_token))
		{
			cur_token = cur_token->next;
			continue;
		}
		if ((cur_token->type & WORD) && !(cur_token->type & SQUOTE))
		{
			expand_pidenv(cur_token);
			expand_env(cur_token, env);
		}
		cur_token = cur_token->next;
	}
}
