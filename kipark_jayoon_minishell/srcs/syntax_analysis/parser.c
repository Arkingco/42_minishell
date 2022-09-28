/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/28 15:11:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.h"
#include "parser.h"

//print parsing list
// #include <stdio.h>
// static void 	print_parsing_list(t_parsing_list *l_parsing)
// {
// 	t_simple_cmd	*head_cmd;
// 	t_redir_chunk	*head_redir;

// 	if (!l_parsing)
// 		return ;

// 	printf("\n\n*parsing list*\n\n");
// 	while (l_parsing)
// 	{
// 		// simple cmd
// 		if (l_parsing->l_simple_cmd)
// 		{
// 			head_cmd = l_parsing->l_simple_cmd;
// 			while (head_cmd)
// 			{
// 				printf("****simple cmd****\n");
// 				printf("simple cmd:		%s\n\n", head_cmd->str);
// 				head_cmd = head_cmd->next;
// 			}
// 		}
// 		// redirection
// 		if (l_parsing->redir_iter)
// 		{
// 			// redirection input
// 			head_redir = l_parsing->redir_iter->l_input;
// 			while (head_redir)
// 			{
// 				printf("****Input_redirection****\n");
// 				printf("redirection:		%s\n", head_redir->redir);
// 				printf("file_path:		%s\n\n", head_redir->file_name);
// 				head_redir = head_redir->next;
// 			}
// 			// redirection output
// 			head_redir = l_parsing->redir_iter->l_output;
// 			while (head_redir)
// 			{
// 				printf("****Output_redirection****\n");
// 				printf("redirection:		%s\n", head_redir->redir);
// 				printf("file_path:		%s\n\n", head_redir->file_name);
// 				head_redir = head_redir->next;
// 			}
// 		}
// 		if (l_parsing->next)
// 			printf("------------------ next -------------- \n\n");	
// 		l_parsing = l_parsing->next;
// 	}
// }

t_parsing_list	*parse_tokenized_data(t_token *l_token)
{
	t_parsing_list	*l_parsing;

	l_parsing = check_syntax_and_set_parsing_list(l_token);

	//print parsing list
	// print_parsing_list(l_parsing);
	return (l_parsing);
}
