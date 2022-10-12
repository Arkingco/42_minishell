/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:55:36 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/10 15:38:09 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int	safe_open(char *path, int oflag)
{
	int	fd;

	fd = 0;
	if (oflag == O_RDONLY)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(path);
		exit(1);
	}
	is_exceed_max_fd(fd);
	return (fd);
}
