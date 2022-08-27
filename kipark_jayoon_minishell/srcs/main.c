/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/27 15:46:43 by kipark           ###   ########seoul.kr  */
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
