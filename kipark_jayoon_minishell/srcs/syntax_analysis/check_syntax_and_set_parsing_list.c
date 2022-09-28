/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_and_set_parsing_list.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:43:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/27 15:31:32 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

//libft
#include "libft.h"

// static void	do_it_at_word(void)
// {
// }
// static void	do_it_at_redirection(void)
// {
// }
// static void	do_it_at_pipe(void)
// {
// }

// simple command(exec_path) or redir_iter(redirection)
static int	is_pipe(char type)
{
	if (type == T_PIPE)
		return (0);
	return (1);
}

static void	init_redir_iter(t_parsing_list *l_parsing)
{
	l_parsing->redir_iter 
		= (t_redir_iter *)ft_safe_malloc(sizeof(t_redir_iter));
	l_parsing->redir_iter->l_input = NULL;
	l_parsing->redir_iter->l_output = NULL;
}

t_parsing_list	*check_syntax_and_set_parsing_list(t_token *l_token)
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
