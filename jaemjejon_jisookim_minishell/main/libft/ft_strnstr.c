/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:34 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 17:08:56 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_is_there(const char *haystack, const char *needle, size_t len)
{
	while (len-- > 0)
	{
		if (*haystack++ != *needle++)
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	haystack_len;
	int	needle_len;
	int	count;
	int	count_limit;

	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (n >= (size_t)haystack_len)
		count_limit = haystack_len - needle_len + 1;
	else
		count_limit = n - needle_len + 1;
	count = 0;
	while (count < count_limit)
	{
		if (check_is_there(haystack + count, needle, needle_len))
			return ((char *)haystack + count);
		count++;
	}
	return (0);
}
