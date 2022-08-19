/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:03:53 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 02:37:59 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char *c)
{
	if ((9 <= *c && *c <= 13) || *c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	char	*digit_ptr;

	result = 0;
	sign = 1;
	while (is_space(str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	digit_ptr = (char *)str;
	while (ft_isdigit(*digit_ptr))
	{
		result *= 10;
		result += (*digit_ptr - '0');
		digit_ptr++;
	}
	return (result * sign);
}
