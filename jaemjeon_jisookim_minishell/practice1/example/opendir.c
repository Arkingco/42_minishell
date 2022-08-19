/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:27:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 02:29:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>


// /* structure describing an open directory. */
// typedef struct {
// 	int	__dd_fd;	/* file descriptor associated with directory */
// 	long	__dd_loc;	/* offset in current buffer */
// 	long	__dd_size;	/* amount of data returned */
// 	char	*__dd_buf;	/* data buffer */
// 	int	__dd_len;	/* size of data buffer */
// 	long	__dd_seek;	/* magic cookie returned */
// 	__unused long	__padding; /* (__dd_rewind space left for bincompat) */
// 	int	__dd_flags;	/* flags for readdir */
// 	__darwin_pthread_mutex_t __dd_lock; /* for thread locking */
// 	struct _telldir *__dd_td; /* telldir position recording */
// } DIR;

void	print_file_info(struct dirent *dirp)
{
	printf("string      file_name : |%s|\n", dirp->d_name);
	printf("__uint16_t  d_namlen  : |%hu|\n", dirp->d_namlen);
	printf("__uint8_t   d_type    : |%c|\n", dirp->d_type);
	printf("__uint64_t  d_ino     : |%llu|\n", dirp->d_ino);
	printf("__uint16_t  d_reclen  : |%hu|\n", dirp->d_reclen);
	printf("__uint64_t  d_seekoff : |%llu|\n", dirp->d_seekoff);
	printf("\n\n");
}
/******************************************************
 * 인자로 받은 폴더를 열고(절대경로, 상대경로 둘다 가능)
 * 폴더에 대한 포인터(DIR *dp)를 opendir로 받아
 * readdir를 반복해 해당폴더의 모든 파일명을 출력하는 프로그램
******************************************************/
int main(int argc, char *argv[])
{
	DIR	*dp;
	struct dirent *dirp;
	if (argc != 2)
	{
		fprintf(stderr, "give me only one dir_name\n");
		exit(EXIT_FAILURE);
	}
	dp = opendir(argv[1]);
	if (dp == NULL)
	{
		fprintf(stderr, "no exist dir\n");
		exit(EXIT_FAILURE);
	}
	printf("__dd_fd : %d\n\n", dp->__dd_fd);
	while ((dirp = readdir(dp)) != NULL)
		print_file_info(dirp);
	closedir(dp);
	exit(EXIT_SUCCESS);
}
