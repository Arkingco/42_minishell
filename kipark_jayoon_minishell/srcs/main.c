/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/23 18:01:44 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lexer.h"
#include "parser.h"
#include "terminal.h"
#include "execution.h"
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

static void	syntax_error_continue(char *line, t_token *token, \
													t_parsing_list *l_parsing)
{
	add_history(line);
	free_all(line, token, l_parsing);
}

int main(int argc, char **argv, char **envp)
{
	char			*line;
	t_token 		*token;
	t_parsing_list	*l_parsing;
	t_env			*curr_envp;
	
	l_parsing = NULL;
	token = NULL;
	init_terminal();
	check_argument(argc, argv);
	curr_envp = set_shell_env_list(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(curr_envp, line);
			if (token == NULL)
			{
				syntax_error_continue(line, token, l_parsing);
				continue ;
			}
			l_parsing = parser(token);
			if (l_parsing == NULL)
			{
				syntax_error_continue(line, token, l_parsing);
				continue ;
			}
			execute_cmd(l_parsing, curr_envp);
			add_history(line);
			free_all(line, token, l_parsing);
		}
		else
			exit_readline_return_null();
	}
	return (0);
}
