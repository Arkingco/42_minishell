/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/02 16:06:12 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all_at_fail(char ***p_ret, int i)
{
	char	**ret;

	ret = *p_ret;
	while (i)
	{
		free(ret[i]);
		ret[i] = NULL;
		i--;
	}
	free(*p_ret);
	*p_ret = NULL;
}

static const char	*find_word_of_edge(const char *curr, const char c, \
										const char **start, const char **end)
{
	t_delimeter	is_delimeter;

	is_delimeter = DEL_FIRST_CALL;
	*end = NULL;
	while (*curr == c)
		curr++;
	while (*curr && *end == NULL)
	{
		if (*curr == c)
		{
			*end = curr - 1;
			break ;
		}
		if (is_delimeter == DEL_FIRST_CALL)
			*start = curr;
		is_delimeter = DEL_NO;
		curr++;
	}
	if (*curr == '\0' && is_delimeter == DEL_NO)
		*end = curr -1;
	return (curr);
}

static void	make_ret(char ***p_ret, char const *str, char c, int n)
{
	int			i;
	int			j;
	const char	*start;
	const char	*end;
	const char	*curr;

	i = 0;
	curr = str;
	while (i < n)
	{
		j = 0;
		curr = find_word_of_edge(curr, c, &start, &end);
		(*p_ret)[i] = (char *)malloc((end - start + 1) + 1);
		if (!(*p_ret)[i])
		{
			free_all_at_fail(p_ret, i);
			return ;
		}
		while (start <= end)
			(*p_ret)[i][j++] = *start++;
		(*p_ret)[i++][j] = '\0';
	}
}

static int	count_word(char const *str, char c)
{
	int			cnt;
	t_delimeter	is_delimeter;

	cnt = 0;
	is_delimeter = DEL_FIRST_CALL;
	while (*str)
	{
		if (*str == c)
		{
			is_delimeter = DEL_YES;
			str++;
			continue ;
		}
		if (is_delimeter == DEL_YES || is_delimeter == DEL_FIRST_CALL)
			cnt++;
		is_delimeter = DEL_NO;
		str++;
	}
	return (cnt);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		num_word;

	if (!str)
		return (NULL);
	num_word = count_word(str, c);
	ret = malloc(sizeof(char *) * (num_word + 1));
	if (!ret)
		return (NULL);
	ret[num_word] = NULL;
	make_ret(&ret, str, c, num_word);
	return (ret);
}
