/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:55:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 04:17:35 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************************************************************
 * 0, 1, 2번의 fd를 isatty에 넣었을때의 반환값을 출력하고,
 * 파일을 하나열어서 그 fd를 isatty에 넣었을때의 반환값을 출력해보는 프로그램
 *************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		return_value_int;
	char	*return_value_char_p;
	int		fd_index;
	int		file_fd;

	fd_index = 0;
	while (fd_index <= 2)
	{
		printf("return of isatty(%d) : %d\n", fd_index, isatty(fd_index));
		printf("return of ttyname(%d) : %s\n", fd_index, ttyname(fd_index));
		fd_index++;
	}
	printf("return of isatty(9999) : %d\n", isatty(9999));
	printf("return of ttyname(9999) : %s\n", ttyname(9999));
	printf("\n\n");
	file_fd = open("something_folder/something_file", O_RDONLY);
	printf("return_value of isatty(opened_file) : %d\n", isatty(file_fd));
	printf("return of ttyname(%d) : %s\n", file_fd, ttyname(file_fd));
	close(file_fd);
	return (0);
}
