/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:02:29 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/12 18:51:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i < len)
		i++;
	while (ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, len - i + 1);
	return (str);
}
