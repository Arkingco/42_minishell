/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/24 15:36:03 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "prompt.h"
#include "minishell.h"
#include "parse.h"

int main(void)
{
	char	*line;
	t_token *token;
	
	init_terminal();
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			
			token = tokenize(line);
			parser(token);
			// syntax_analysis();
			// execute();
			
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
