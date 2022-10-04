/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:00:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/04 16:56:29 by kipark           ###   ########seoul.kr  */
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

//norm
#include "exit_status.h"
int main(int argc, char **argv, char **envp)
{
	char			*line;
	t_token 		*token;
	t_parsing_list	*l_parsing;
	t_env			*l_env;

	//test
	// int	i = 2;
	
	l_parsing = NULL;
	token = NULL;
	init_terminal(DEFAULT_TERMINAL);
	check_argument(argc, argv);
	l_env = set_shell_env_list(envp);

	//test
	// while (i--)
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			token = tokenize(l_env, line);
			if (token == NULL)
			{
				syntax_error_continue(line, token, l_parsing);
				continue ;
			}
			l_parsing = parse_tokenized_data(token);
			if (l_parsing == NULL)
			{
				syntax_error_continue(line, token, l_parsing);
				continue ;
			}
			execute_cmd(l_parsing, l_env);
			add_history(line);

			// print exit status
			printf("exit status : %d\n", g_exit_status);
			free_all(line, token, l_parsing);
			token = NULL;
			l_parsing = NULL;
		}
		else
		{
			// free(line);
			exit_readline_return_null();
		}
	}
	return (0);
}
