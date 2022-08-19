/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:13:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 21:28:38 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*buf;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, len + 1);
	return (buf);
}
