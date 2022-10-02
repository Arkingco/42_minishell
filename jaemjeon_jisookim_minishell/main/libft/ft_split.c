/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:45:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 20:49:18 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_alloc_string(char **dst, const char *src, char del)
{
	int		len;

	len = 0;
	while (*src == del)
		src++;
	while (*src != del && *src != '\0')
	{
		src++;
		len++;
	}
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	src -= len;
	ft_strlcpy(*dst, src, len + 1);
	return ((char *)(src + len - 1));
}

static void	free_back(char **table, int idx)
{
	int	f_idx;

	f_idx = 0;
	while (f_idx < idx)
	{
		free(table[f_idx]);
		table[f_idx] = 0;
		f_idx++;
	}
	free(table);
}

char	**ft_split(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		idx;

	idx = 0;
	word_count = ft_count_words(s, c);
	table = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (table == 0)
		return (0);
	while (idx < word_count)
	{
		s = ft_alloc_string(&table[idx], s, c);
		if (s == 0)
		{
			free_back(table, idx);
			return (0);
		}
		s++;
		idx++;
	}
	table[word_count] = 0;
	return (table);
}
