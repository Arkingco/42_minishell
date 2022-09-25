/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:36:42 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 18:55:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cpy_ifs_string(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context;
	cpy_end = cpy_start;
	while (ft_is_ifs(cpy_end))
		cpy_end++;
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start);
	*context = cpy_end;
	return (copied_string);
}

int	is_ifs_word(char *string_value)
{
	while (ft_is_ifs(string_value) == TRUE && *string_value != '\0')
		string_value++;
	if (*string_value == '\0')
		return (TRUE);
	else
		return (FALSE);
}
