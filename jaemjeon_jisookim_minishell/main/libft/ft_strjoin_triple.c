/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_triple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:52:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/26 18:40:20 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_null_count(char *s1, char *s2, char *s3)
{
	int	null_count;

	null_count = 0;
	if (s1 == NULL)
		null_count++;
	if (s2 == NULL)
		null_count++;
	if (s3 == NULL)
		null_count++;
	return (null_count);
}

static char	*get_not_null_pointer(char *s1, char *s2, char *s3)
{
	if (s1 != NULL)
		return (s1);
	else if (s2 != NULL)
		return (s2);
	else if (s3 != NULL)
		return (s3);
	else
		return (NULL);
}

static char	*strjoin_two(char *s1, char *s2, char *s3)
{
	if (s1 == NULL)
		return (ft_strjoin(s2, s3));
	else if (s2 == NULL)
		return (ft_strjoin(s1, s3));
	else if (s3 == NULL)
		return (ft_strjoin(s1, s2));
	else
		return (NULL);
}

char	*ft_strjoin_triple(char *s1, char *s2, char *s3)
{
	char	*first_joined;
	char	*second_joined;

	if (get_null_count(s1, s2, s3) == 3)
		return (NULL);
	else if (get_null_count(s1, s2, s3) == 2)
		return (get_not_null_pointer(s1, s2, s3));
	else if (get_null_count(s1, s2, s3) == 1)
		return (strjoin_two(s1, s2, s3));
	else
	{
		first_joined = ft_strjoin(s1, s2);
		second_joined = ft_strjoin(first_joined, s3);
		free(first_joined);
		return (second_joined);
	}
}
