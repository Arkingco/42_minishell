/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:42:33 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/04 13:21:33 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

// add_history로  history를 추가하면 위아래 방향키로 history를 불러올 수 있다.
// 단, readline으로 읽을 준비가 되어있는 상태여야지만 불러올 수 있다.
int	main(int argc, char *argv[], char *envp[])
{
	int		return_val;
	char	*new_line;

	while (1)
	{
		new_line = readline("input new line : ");
		if (new_line == NULL)
		{
			printf("\nEOF is inputed\n");
			exit(0);
		}
		return_val = add_history(new_line);
		printf("return_value of add_history : %d\n", return_val);
		printf("[if you want to check your command, press up arrow button]\n");
		free(new_line);
	}
	return (0);
}
