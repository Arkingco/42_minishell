/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_pid_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:11:28 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 21:06:05 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

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
