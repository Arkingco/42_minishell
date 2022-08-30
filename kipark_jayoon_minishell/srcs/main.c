/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/30 15:48:38 by kipark           ###   ########seoul.kr  */
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
#include "env.h"

static void	free_main_line_and_token(char *line, t_token *token)
{
	free(line);
	line = NULL;
	token_free(token);
}

static int	check_argument(int argc, char **argv)
{
	if (argc > 2)
		return (1);
	if (argv[1] != NULL)
		return (1);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token *token;
	t_env	*env;

	init_terminal();
	if (check_argument(argc, argv))
		return (1);
	env = set_shell_env_list(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(env, line);
			parser(token);
			// syntax_analysis();
			// execute();
			add_history(line);
			free_main_line_and_token(line, token);
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
