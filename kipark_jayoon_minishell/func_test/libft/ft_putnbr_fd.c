/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:15:21 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/20 20:07:18 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_recursive(long int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd_recursive(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	long_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n = (long int)n * (-1);
	}
	else
		long_n = n;
	ft_putnbr_fd_recursive(long_n, fd);
}
