/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/01 16:04:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lexer.h"
#include "parser.h"
#include "terminal.h"
#include "minishell.h"

int main(void)
{
	char			*line;
	t_token 		*token;
	t_parsing_list	*l_parsing;
	
	init_terminal();
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(line);
			l_parsing = parser(token);
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
