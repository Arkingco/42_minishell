/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:47:53 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 17:08:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

// ifdef __DARWIN_STRUCT_STAT64

	// dev_t == int
	// mode_t == unsigned short
	// nlin_t == unsigned short
	// __darwin_ino64_t == unsigned long long
	// uid_t == unsigned int
	// git_t ==  unsigned int
struct stat {
	dev_t		st_dev;                 /* [XSI] ID of device containing file */
	mode_t		st_mode;                /* [XSI] Mode of file (see below) */
	nlink_t		st_nlink;               /* [XSI] Number of hard links */
	__darwin_ino64_t st_ino;                /* [XSI] File serial number */
	uid_t		st_uid;                 /* [XSI] User ID of the file */
	gid_t		st_gid;                 /* [XSI] Group ID of the file */
	dev_t		st_rdev;                /* [XSI] Device ID */

	struct timespec
	{
		__darwin_time_t tv_sec;
		//__darwin_time_t == long
		long            tv_nsec;
	};
	struct timespec st_atimespec;           /* time of last access */
	struct timespec st_mtimespec;           /* time of last data modification */
	struct timespec st_ctimespec;           /* time of last status change */
	struct timespec st_birthtimespec;       /* time of file creation(birth) */

	off_t		st_size;                /* [XSI] file size, in bytes */
	blkcnt_t	st_blocks;              /* [XSI] blocks allocated for file */
	blksize_t	st_blksize;             /* [XSI] optimal blocksize for I/O */
	__uint32_t	st_flags;               /* user defined flags for file */
	__uint32_t	st_gen;                 /* file generation number */
	__int32_t	st_lspare;              /* RESERVED: DO NOT USE! */
	__int64_t	st_qspare[2];           /* RESERVED: DO NOT USE! */
}

int	main()
{
	DIR				*dp;
	struct stat 	*s_stat;
	struct dirent	*s_dirent;

	dp = opendir("./");
	if (dp == NULL)
	{
		fprintf(stderr, "error in opening currnet folder\n");
		exit(1);
	}
	while ((s_dirent = readdir(dp)) != NULL)
		printf("%s")
	stat("./stat.c", s_A);
	
	printf()
	return 0;
}