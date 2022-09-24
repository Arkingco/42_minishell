/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:36:42 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 14:46:39 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
현재 포인터의 ifs부터 연속된 ifs들을 쭉 복사하여 반환함.
*/
char	*cpy_ifs_string(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context; // 문맥 받아옴
	cpy_end = cpy_start;
	while (ft_is_ifs(cpy_end)) // ifs가 아닌 문자가 나올때까지 계속 읽음
		cpy_end++;
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start); // ifs덩어리를 복사
	*context = cpy_end; // 문맥 교환
	return (copied_string); // 복사한 ifs덩어리 반환
}

/*
ifs로만 이루어진 문자열인지 판단
*/
int	is_ifs_word(char *string_value)
{
	while (ft_is_ifs(string_value) == TRUE && *string_value != '\0')
		string_value++;
	if (*string_value == '\0')
		return (TRUE);
	else
		return (FALSE);
}
