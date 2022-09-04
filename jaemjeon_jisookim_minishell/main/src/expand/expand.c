/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:47:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/05 01:19:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expand_pidenv(t_token *token)
{
	char	*pid_suspect;
	// char	*tmp_string;

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
			ft_memmove(pid_suspect, pid_suspect + 2, \
									ft_strlen(pid_suspect) + 1); // $$를 지워버림.
			token->type |= EXPANDED; // 그냥 지워진게 아니라 pid로 확장이 되었다는 맥락이니까 expanded flag도 박아줌
		}
	}
}

/*
expand_env_withdollar에서 호출하는 함수로, $를 가르키는 포인터, envkey를 지나킬 포인터를 받는다.
1. 먼저 envkey의 다음칸으로 포인터를 옮겨준다.
2. 만약 dollar_p와 envkey_end가 1차이라면 실제론 $하나만 있었으니까 확장시키지 않고 그냥 $를 복사하여 반환
3. envkey를 찾았는데 (1) 해당되는 환경변수가 존재하는 경우 (2) 존재하지 않는경우 로 나뉜다.
3-(1). ft_getenv로 찾은 value값을 반환해줌
3-(2). 빈문자열을 복사하여 반환.
*/
char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env)
{
	char	*expanded_string;
	char	*env_key;
	char	*env_value;

	__skip_envkey(envkey_end); // 1
	if (doller_p + 1 == *envkey_end) // 2
	{
		expanded_string = ft_strdup("$");
		return (expanded_string);
	}
	else
	{
		env_key = ft_substr(doller_p, 1, *envkey_end - doller_p - 1);
		env_value = ft_getenv(env, env_key); // 3
		if (env_value != NULL)	// 3-(1)
			expanded_string = ft_strdup(env_value);
		else					// 3-(2)
			expanded_string = ft_strdup("");
		free(env_key);
		return (expanded_string);
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
prev에 할당된 메모리에서 raise_size만큼 더 할당량을 늘리고 문자열을 복사해준다.
*/
char	*raise_buffer(char *prev, int raise_size)
{
	char	*raised_buffer;

	raised_buffer = (char *)ft_calloc(1, ft_strlen(prev) + raise_size + 1);
	ft_strlcpy(raised_buffer, prev, ft_strlen(prev) + 1); // 널문자까지의 사이즈를 넣어줘야함
	free(prev);
	return (raised_buffer);
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

void	expander(t_token **tokne_lst, t_envlst *env)
{
	t_token	*cur_token;

	cur_token = *tokne_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & WORD) && !(cur_token->type & SQUOTE))
		{
			expand_pidenv(cur_token);
			expand_env(cur_token, env);
		}
		cur_token = cur_token->next;
	}
}