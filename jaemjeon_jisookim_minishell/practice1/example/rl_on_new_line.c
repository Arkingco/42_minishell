/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_on_new_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:23:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/04 13:22:09 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>

int main()
{
	char	*line_you_write;
	int		return_val;

	while (1)
	{
		line_you_write = readline("write your line : ");
		if (line_you_write == NULL)
			break ;
		return_val = rl_on_new_line();
		printf("return_val : %d\n", return_val);
		printf("%s\n", line_you_write);
		free(line_you_write);
	}
	return 0;
}

//not finisthed
