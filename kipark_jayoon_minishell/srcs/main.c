/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/01 11:45:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexer.h"
#include "minishell.h"
#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

int main(void)
{
	char			*line;
	t_token 		*token;
	t_parsing_list	l_parsing;
	
	init_terminal();
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(line);
			parser(token, &l_parsing);
			execute_cmd(&l_parsing);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
