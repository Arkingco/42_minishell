/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 02:17:11 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_write_char(const char *chr, int fd)
{
	write(fd, chr, 1);
	return (1);
}

int	ft_matched_format(va_list ap, const char *cursor, int fd)
{
	if (*cursor == 'c')
		return (ft_print_char(ap, fd));
	else if (*cursor == 's')
		return (ft_print_string(ap, fd));
	else if (*cursor == 'p')
		return (ft_print_pointer(ap, fd));
	else if (*cursor == 'd' || *cursor == 'i')
		return (ft_print_decimal(ap, fd));
	else if (*cursor == 'x' || *cursor == 'X' || *cursor == 'u')
		return (ft_print_uibase(ap, *cursor, fd));
	else
		return (ft_write_char("%", fd));
}

int	printf_fd(int fd, const char *format, ...)
{
	va_list		ap;
	int			print_len;
	const char	*format_cursor;

	print_len = 0;
	format_cursor = format;
	va_start(ap, format);
	while (*format_cursor != 0)
	{
		if (*format_cursor == '%')
		{
			print_len += ft_matched_format(ap, format_cursor + 1, fd);
			format_cursor += 2;
		}
		else
		{
			print_len += ft_write_char(format_cursor, fd);
			format_cursor++;
		}
	}
	va_end(ap);
	return (print_len);
}
