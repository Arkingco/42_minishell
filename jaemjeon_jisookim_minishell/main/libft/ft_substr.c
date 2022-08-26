/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/15 20:49:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_emp_string(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char));
	if (result == 0)
		return (0);
	*result = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	char		*result;

	s_len = ft_strlen(s);
	if (start <= s_len)
	{
		if (start + len <= s_len + 1)
		{
			result = (char *)malloc(sizeof(char) * (len + 1));
			if (result == 0)
				return (0);
			ft_strlcpy(result, s + start, len + 1);
		}
		else
		{
			result = (char *)malloc(sizeof(char) * (s_len - start + 2));
			if (result == 0)
				return (0);
			ft_strlcpy(result, s + start, s_len - start + 2);
		}
	}
	else
		return (make_emp_string());
	return (result);
}
