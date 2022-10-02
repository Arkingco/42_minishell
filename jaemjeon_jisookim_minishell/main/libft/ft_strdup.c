/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:10 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 21:27:53 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s2 == 0)
	{
		free(s2);
		s2 = 0;
		return (0);
	}
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
