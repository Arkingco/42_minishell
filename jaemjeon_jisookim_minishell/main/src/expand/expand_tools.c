/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 02:07:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 21:12:29 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		env_key = 0;
		return (expanded_string);
	}
}

/*
prev에 할당된 메모리에서 raise_size만큼 더 할당량을 늘리고 문자열을 복사해준다.
*/
char	*raise_buffer(char *prev, int raise_size)
{
	char	*raised_buffer;

	raised_buffer = (char *)ft_calloc(1, ft_strlen(prev) + raise_size + 1);
	if (raised_buffer == NULL)
	{
		free(raised_buffer);
		ft_error_exit(1, "exit with malloc error");
	}
	ft_strlcpy(raised_buffer, prev, ft_strlen(prev) + 1); // 널문자까지의 사이즈를 넣어줘야함
	free(prev);
	prev = 0;
	return (raised_buffer);
}
