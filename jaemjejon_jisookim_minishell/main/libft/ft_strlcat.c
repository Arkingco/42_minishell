/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/14 22:27:48 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	else
	{
		if (src_len + dst_len < dstsize)
		{
			ft_strlcpy(dst + dst_len, src, src_len + 1);
		}
		else
		{
			ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
		}
	}
	return (dst_len + src_len);
}
