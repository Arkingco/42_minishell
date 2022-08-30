/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:10:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/30 16:26:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_fork()
{
		if (fork() == -1)
			exit(1);
}


void	ft_open(const char *filename, int flags)
{
	if (open(filename, flags) == -1)
		exit(1);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		exit(1);
}

// int	ft_exceve(const char *filename, char *const argv[], char *const envp[])
// {
// 	if (exceve(filename, argv, envp) == -1)
// 		exit();
// 	return ()
// }

// dup2는 새 서술자의 값을 fd2로 지정합니다. 
// 만일 fd2가 이미 열려있으면 fd2를 닫은 후 복제가 됩니다. 
// 역시 성공시 새 파일 서술자, 오류시 -1을 반환
void ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit(1);
}