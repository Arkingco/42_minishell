/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:09:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/04 21:15:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	DIR	*dp;

	if ((dp = opendir("not_exist_dir")) == NULL)
	{
		perror("before collon ");
		// 현재  error에 해당하는 에러메시지를 perror의 인자에 넣은 문자열뒤에 같이 출력해줌.
		// before collon : No such file or directory 가 출력됨.
		exit(1);
	}
	else
	{
		printf("you input exist dir\n");
		exit(0);
	}
}