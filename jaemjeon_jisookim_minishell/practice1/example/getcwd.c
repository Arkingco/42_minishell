/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:59:59 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 03:19:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// int	main()
// {
// 	char	*dir;
// 	int		return_val;

// 	dir = getcwd(NULL, 0); // buffer에 NULL을 넣었으므로 새롭게 할당되어 반환됨.
// 	printf("%s\n", dir);   // /Users/jaemjeon/projects/minishell 출력
// 	free(dir);


// 	return_val = chdir("new_folder"); // 상대경로 가능함
// 	printf("%d\n", return_val);
// 	// new_folder라는 폴더가 있으면 0반환후 dir변경.
// 	// 없으면 -1반환후 현재 dir유지.


// 	dir = getcwd(NULL, 0);
// 	printf("%s\n", dir);
// 	free(dir);


// 	chdir("/"); // 절대 경로도 가능함.
// 	dir = getcwd(NULL, 0);
// 	printf("%s\n", dir);
// 	free(dir);
// }
int main()
{
  char *return_value;
	char buf[1024];

	return_value = getcwd(buf, 1024);
	printf("address of return_value : %p\n", return_value);
	printf("address of buf          : %p\n", buf);
	printf("return_value : %s\n", return_value);
	printf("buf          : %s\n", buf);
}
