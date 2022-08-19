/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:09:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/25 16:37:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_utils(ssize_t *p_result, int *p_sign)
{
	*p_result = 0;
	*p_sign = 1;
}

static const char	*pass_space(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static const char	*check_sign(const char *str, int *p_sign)
{
	if (ft_issign(*str))
	{
		if (*str == '-')
			*p_sign = -1;
		str++;
	}
	return (str);
}

static size_t	do_atol(const char *str, ssize_t *p_result)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*str))
	{
		*p_result = 10 * *p_result + *str - '0';
		str++;
		len++;
	}
	return (len);
}

ssize_t	ft_atol(const char *str)
{
	int		sign;
	ssize_t	result;
	size_t	len;

	if (!str)
		return (0);
	init_utils(&result, &sign);
	str = pass_space(str);
	str = check_sign(str, &sign);
	len = do_atol(str, &result);
	if (len > 19 && sign == 1)
		return ((ssize_t)INT_MAX + 1);
	else if (len > 19 && sign == -1)
		return ((ssize_t)INT_MIN - 1);
	return ((ssize_t)sign * result);
}
