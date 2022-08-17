/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:44:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/14 16:03:02 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && needle_len + i <= len)
	{
		if (haystack[i] == *(needle)
			&& !ft_memcmp(haystack + i, needle, needle_len))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
