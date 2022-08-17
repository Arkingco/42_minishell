/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:12:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/12 20:50:42 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	*allocate_str_by_length(size_t s_len, size_t len)
{
	char	*str;

	if (s_len < len)
		str = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

static void	copy_s_to_ret(t_str *ps, unsigned int start, size_t s_len, \
							size_t len)
{
	size_t	i;

	i = 0;
	if (start < s_len)
	{
		while (i < len)
		{
			if (ps->src[i] == '\0')
				break ;
			ps->dst[i] = ps->src[start + i];
			i++;
		}
	}
	ps->dst[i] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	t_str	str;
	size_t	s_len;

	if (!s)
		return (NULL);
	str.src = (char *)s;
	s_len = ft_strlen(s);
	str.dst = allocate_str_by_length(s_len, len);
	if (str.dst)
		copy_s_to_ret(&str, start, s_len, len);
	return (str.dst);
}
