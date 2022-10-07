/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:55:36 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 10:37:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <fcntl.h>
#include "libft.h"

int	safe_open(char *path, int oflag)
{
	int	fd;

	fd = 0;
	if (oflag == O_RDONLY)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, 0666);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	is_exceed_max_fd(fd);
	return (fd);
}
