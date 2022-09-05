/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 04:26:09 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cal_num_len(long c)
{
	int	len;

	if (c == 0)
		return (1);
	len = 0;
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static char	*ft_make_neg_num(long num, int num_len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (num_len + 2));
	if (result == 0)
		return (0);
	result[num_len + 1] = '\0';
	while (num_len > 0)
	{
		result[num_len] = (num % 10) + '0';
		num /= 10;
		num_len--;
	}
	result[num_len] = '-';
	return (result);
}

static char	*ft_make_pos_num(long num, int num_len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (result == 0)
		return (0);
	result[num_len] = '\0';
	while (--num_len >= 0)
	{
		result[num_len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

char	*ft_itoa(int c)
{
	long	num;
	int		num_len;

	num = c;
	if (num < 0)
	{
		num *= -1;
		num_len = ft_cal_num_len(num);
		return (ft_make_neg_num(num, num_len));
	}
	else
	{
		num_len = ft_cal_num_len(num);
		return (ft_make_pos_num(num, num_len));
	}
}
