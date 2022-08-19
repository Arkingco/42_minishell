/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:12:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/01 12:35:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret1;
	ssize_t	ret2;

	if (!s)
		return (0);
	ret1 = write(fd, s, ft_strlen(s));
	ret2 = write(fd, "\n", 1);
	if (ret1 < 0 || ret2 < 0)
		return (-1);
	return (ret1 + ret2);
}
