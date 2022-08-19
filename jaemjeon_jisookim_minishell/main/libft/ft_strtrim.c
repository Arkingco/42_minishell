/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:42 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 17:53:38 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char chr, const char *set)
{
	while (*set != '\0')
	{
		if (chr == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char		*result;
	int			result_len;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (is_in_set(*start, set))
	{
		start++;
	}
	while (is_in_set(*end, set))
	{
		if (start > end)
			break ;
		end--;
	}
	result_len = end - start + 1;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == 0)
		return (0);
	ft_strlcpy(result, start, result_len + 1);
	return (result);
}
