/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/16 16:44:59 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "prompt.h"
#include "minishell.h"

int main(void)
{
	int		ret;
	char	*line;
	
	ret = 1;
	init_terminal();
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			if (ret)
				printf("output> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
