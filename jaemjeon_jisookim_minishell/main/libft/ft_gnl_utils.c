/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:05:48 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 19:52:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_strlen(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, int c)
{
	char	find;
	int		i;

	if (s == 0)
		return (0);
	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return (s + i);
		i++;
	}
	if (s[i] == find)
		return (s + i);
	return (0);
}

void	ft_gnl_free(char **s1)
{
	if (*s1 == 0)
		return ;
	free(*s1);
	*s1 = 0;
	return ;
}

char	*strjoin_process(char *s1, char *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	if (len == 0)
		return (s1);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
	{
		ft_gnl_free(&s1);
		return (0);
	}
	str = strjoin_process(s1, s2, str);
	ft_gnl_free(&s1);
	return (str);
}
