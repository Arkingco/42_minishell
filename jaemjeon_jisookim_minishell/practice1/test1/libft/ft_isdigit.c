/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:00:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/09 20:27:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_in_uchar(int num)
{
	if (0 <= num && num <= 255)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	unsigned char	test_chr;

	if (is_in_uchar(c) == 0)
		return (0);
	test_chr = c;
	if ('0' <= test_chr && test_chr <= '9')
		return (1);
	return (0);
}
