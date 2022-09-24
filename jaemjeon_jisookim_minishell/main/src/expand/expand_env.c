/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:02:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 16:31:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

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
	else if (*cpy_end == '?')
	{
		expanded_string = ft_itoa(g_errno);
		cpy_end++;
	}
	else
	{
		expanded_string = __get_envvalue(cpy_start, &cpy_end, env); // 확장하여 반환
		token->type |= EXPANDED; // 확장된 토큰이라는 flag설정
	}
	*context = cpy_end; // 다음 $를 찾아 가야하니까 지금까지 읽은곳 다음 칸으로 문맥변경
	return (expanded_string);
}



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
