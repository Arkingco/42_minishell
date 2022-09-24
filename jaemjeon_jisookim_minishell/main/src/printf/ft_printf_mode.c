/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:26:22 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 21:15:15 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_char(va_list ap, int fd)
{
	char	output;

	output = va_arg(ap, int);
	write(fd, &output, 1);
	return (1);
}

int	ft_print_string(va_list ap, int fd)
{
	char	*output;
	int		len;

	output = va_arg(ap, char *);
	if (output == 0)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(output);
	write(fd, output, len);
	return (len);
}

int	ft_print_pointer(va_list ap, int fd)
{
	unsigned long	output_long;
	char			*output;
	int				len;

	output_long = va_arg(ap, unsigned long);
	output = ft_longto_other_base(output_long, "0123456789abcdef");
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(fd, "0x", 2);
	write(fd, output, len);
	free(output);
	output = 0;
	return (len + 2);
}

int	ft_print_decimal(va_list ap, int fd)
{
	int		output_int;
	int		len;
	char	*output;

	output_int = va_arg(ap, int);
	output = ft_itoa(output_int);
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(fd, output, len);
	free(output);
	output = 0;
	return (len);
}

int	ft_print_uibase(va_list ap, char type, int fd)
{
	unsigned int	output_ui;
	char			*output;
	int				len;

	output_ui = va_arg(ap, unsigned int);
	if (type == 'x')
		output = ft_uito_other_base(output_ui, "0123456789abcdef");
	else if (type == 'X')
		output = ft_uito_other_base(output_ui, "0123456789ABCDEF");
	else
		output = ft_uito_other_base(output_ui, "0123456789");
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(fd, output, len);
	free(output);
	output = 0;
	return (len);
}
