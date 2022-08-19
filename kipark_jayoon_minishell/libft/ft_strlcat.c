/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:47:03 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/06 21:14:15 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen < dstsize)
	{
		while (*dst)
			dst++;
		while (*src && dstsize - dstlen - 1)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = '\0';
		return (dstlen + srclen);
	}
	return (srclen + dstsize);
}
