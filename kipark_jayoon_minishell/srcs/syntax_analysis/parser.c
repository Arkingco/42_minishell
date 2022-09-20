/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 23:11:21 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.h"
#include "parser.h"

//print parsing list
#include <stdio.h>
static void 	print_parsing_list(t_parsing_list *l_parsing)
{
	t_simple_cmd	*head_cmd;
	t_redir_chunk	*head_redir;

	if (!l_parsing)
		printf("List is empty\n");

	printf("\n\n****parsing list****\n\n");
	while (l_parsing)
	{
		// simple cmd
		printf("****simple cmd****");
		head_cmd = l_parsing->l_simple_cmd;
		while (head_cmd)
		{
			printf("simple cmd:		%s\n\n", head_cmd->str);
			head_cmd = head_cmd->next;
		}
		// redirection input
		printf("****Output_redirection****");
		head_redir = l_parsing->redir_iter->l_input;
		while (head_redir)
		{
			printf("redirection:	%s\n\n", head_redir->redir);
			printf("file_path:		%s\n\n", head_redir->file_name);
			head_redir = head_redir->next;
		}
		// redirection input
		printf("****Input_redirection****");
		head_redir = l_parsing->redir_iter->l_output;
		while (head_redir)
		{
			printf("redirection:	%s\n\n", head_redir->redir);
			printf("file_path:		%s\n\n", head_redir->file_name);
			head_redir = head_redir->next;
		}
	}
}

t_parsing_list	*parser(t_token	*l_token)
{
	t_parsing_list	*l_parsing;

	l_parsing = init_parsing_list();
	l_parsing = check_syntax_and_set_parsing_list(l_token, l_parsing);

	//print parsing list
	print_parsing_list(l_parsing);
	return (l_parsing);
}
