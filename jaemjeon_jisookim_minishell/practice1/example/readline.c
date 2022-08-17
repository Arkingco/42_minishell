/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:04:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/03 19:20:37 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h> // printf 사용가능
#include <stdlib.h>

// gcc *.c -lreadline 으로 컴파일
int	main(void)
{
	char	*line_you_write;

	while (1) // EOF를 만나기전까지 무한 반복
	{
		line_you_write = readline("write your line : ");
		if (line_you_write == NULL) // EOF가 들어오면 프로그램 종료
			break ;
		printf("%s\n", line_you_write);
		free(line_you_write); // 입력받은 문자열을 free해줌
	}
	return (0);
}