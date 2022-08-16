/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:50:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/12 19:14:41 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		number_of_digits;
	long	nb;

	nb = n;
	number_of_digits = get_digit(nb);
	if (nb < 0)
	{
		nb *= -1;
		number_of_digits++;
	}
	str = (char *)malloc((number_of_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[number_of_digits--] = '\0';
	while (number_of_digits >= 0)
	{
		str[number_of_digits--] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
