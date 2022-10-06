/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:55:36 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:27:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

int	safe_open(char *path, int oflag)
{
	int	fd;

	fd = 0;
	if (oflag == O_RDONLY)
	{
		fd = open(path, oflag);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	else if (oflag == (O_TRUNC | O_WRONLY | O_CREAT))
	{
		fd = open(path, oflag, 0666);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	else
	{
		fd = open(path, oflag, 0666);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	return (fd);
}
