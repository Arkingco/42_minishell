/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chrset_cnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:08:28 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 15:15:10 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_chrset(char letter, char *chrset)
{
	if (ft_strchr(chrset, letter) != NULL)
		return (1);
	else
		return (0);
}

int	ft_str_chrset_cnt(char *string, char *chrset)
{
	int	count;

	if (string == NULL)
		return (0);
	count = 0;
	while (*string != '\0')
	{
		if (in_chrset(chrset, *string))
			count++;
		string++;
	}
	return (count);
}
