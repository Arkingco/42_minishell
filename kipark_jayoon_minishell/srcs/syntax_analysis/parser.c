/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/02 14:26:48 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

//libft
#include "libft.h"

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



// static void	do_it_at_word(void)
// {
// }
// static void	do_it_at_redirection(void)
// {
// }
// static void	do_it_at_pipe(void)
// {
// }


t_parsing_list	*parse_tokenized_data(t_token *l_token)
{
	void			*node;
	t_parsing_list	*l_parsing;
	t_parsing_list	*head;

	l_token = l_token->next;
	if (!l_token)
		return (NULL);
	if (l_token->type == T_PIPE)
		return ((t_parsing_list *)print_syntax_error());
	l_parsing = init_parsing_list();
	head = l_parsing;
	while (l_token)
	{
		if (is_word(l_token->type))
		{
			node = init_simple_cmd_node(l_token->str);
			add_simple_cmd_node(&l_parsing->l_simple_cmd, (t_simple_cmd *)node);
		}
		else if (is_redirection(l_token->type))
		{
			if (!l_token->next || l_token->next->type != T_WORD)
				return (print_syntax_error());
			if (l_parsing->redir_iter == NULL)
				init_redir_iter(l_parsing);
			node = init_redir_chunk_node(l_token->str, l_token->next->str);
			if (l_token->type == T_INPUT_REDIR || l_token->type == T_HERE_DOC)
				add_redir_chunk_node(&l_parsing->redir_iter->l_input,
					(t_redir_chunk *)node);
			else
				add_redir_chunk_node(&l_parsing->redir_iter->l_output,
					(t_redir_chunk *)node);
			l_token = l_token->next;
		}
		else
		{
			if (!l_token->next || !is_pipe(l_token->next->type))
				return (print_syntax_error());
			node = init_parsing_list();
			add_parsing_list_node(l_parsing, (t_parsing_list *)node);
			l_parsing = l_parsing->next;
		}
		l_token = l_token->next;
	}
	return (head);
}
	//print parsing list
	// print_parsing_list(l_parsing);
