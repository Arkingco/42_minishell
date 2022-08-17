/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyslot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:12:33 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 16:34:43 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;

	fd = open("/dev/ttys000", O_RDWR);
	printf("/dev/ttys000 fd : %d\n", fd);
	write(fd, "hello\n", 6);
	return 0;
}