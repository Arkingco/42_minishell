/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/21 20:25:50 by jayoon           ###   ########.fr       */
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
#include "minishell.h"
#include "env.h"

static void	check_argument(int argc, char **argv)
{
	if (argc > 2)
		exit(1);
	if (argv[1] != NULL)
		exit(1);
	return ;
}

int main(int argc, char **argv, char **envp)
{
	char			*line;
	t_token 		*token;
	t_parsing_list	*l_parsing;
	t_env			*env;
	
	l_parsing = NULL;
	init_terminal();
	check_argument(argc, argv);
	env = set_shell_env_list(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(env, line);
			l_parsing = parser(token);
			if (l_parsing == NULL)
			{
				add_history(line);
				free_all(line, token, l_parsing);
				continue ;
			}
			// syntax_analysis();
			// execute();
			add_history(line);
			free_all(line, token, l_parsing);
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
