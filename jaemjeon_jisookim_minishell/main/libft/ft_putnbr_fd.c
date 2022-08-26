/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:24:36 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 04:28:00 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_num_len(long l_num)
{
	int	len;

	len = 0;
	if (l_num == 0)
		return (1);
	while (l_num != 0)
	{
		l_num /= 10;
		len++;
	}
	return (len);
}

static void	ft_print_digit(long l_num, int locate, int fd)
{
	int		ladder;
	int		count;
	char	digit;

	ladder = 1;
	count = 0;
	while (count++ < locate - 1)
	{
		ladder *= 10;
	}
	digit = (l_num / ladder) % 10 + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l_num;
	int		len;
	int		locate;

	l_num = (long)n;
	if (l_num < 0)
	{
		write(fd, "-", 1);
		l_num *= -1;
	}
	len = ft_num_len(l_num);
	locate = len;
	while (locate > 0)
	{
		ft_print_digit(l_num, locate, fd);
		locate--;
	}
}
