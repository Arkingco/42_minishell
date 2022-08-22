/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:00:29 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/11 17:08:36 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		if (*dst == (unsigned char)c)
			return ((void *)dst);
		dst++;
		i++;
	}
	return (NULL);
}
