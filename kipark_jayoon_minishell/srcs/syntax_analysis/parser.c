/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:22:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>
#include "libft.h"

static void	do_it_at_word(t_token *l_token, t_parsing_list *l_parsing)
{
	t_simple_cmd	*node;

	node = init_simple_cmd_node(l_token->str);
	add_simple_cmd_node(&l_parsing->l_simple_cmd, (t_simple_cmd *)node);
}

static void	*do_it_at_redirection(t_token *l_token, t_parsing_list *l_parsing)
{
	t_redir_chunk	*node;

	if (!l_token->next || l_token->next->type != T_WORD)
		return (print_syntax_error(l_token));
	if (l_parsing->redir_iter == NULL)
		init_redir_iter(l_parsing);
	node = init_redir_chunk_node(l_token->type, l_token->next->str);
	if (l_token->type == T_INPUT_REDIR || l_token->type == T_HERE_DOC)
		add_redir_chunk_node(&l_parsing->redir_iter->l_input,
			(t_redir_chunk *)node);
	else
		add_redir_chunk_node(&l_parsing->redir_iter->l_output,
			(t_redir_chunk *)node);
	return (node);
}

static void	*do_it_at_pipe(t_token *l_token, t_parsing_list *l_parsing)
{
	t_parsing_list	*node;

	if (!l_token->next || !is_pipe(l_token->next->type))
		return (print_syntax_error(l_token));
	node = init_parsing_list();
	add_parsing_list_node(l_parsing, (t_parsing_list *)node);
	return (node);
}

static t_parsing_list	*init_parser(t_parsing_list **l_parsing,
		t_token **l_token)
{
	*l_parsing = init_parsing_list();
	*l_token = (*l_token)->next;
	return (*l_parsing);
}

t_parsing_list	*parse_tokenized_data(t_token *l_token)
{
	t_parsing_list	*l_parsing;
	t_parsing_list	*head;

	if (!l_token->next || l_token->next->type == T_PIPE)
		return ((t_parsing_list *)print_syntax_error(l_token->next));
	head = init_parser(&l_parsing, &l_token);
	while (l_token)
	{
		if (is_word(l_token->type))
			do_it_at_word(l_token, l_parsing);
		else if (is_redirection(l_token->type))
		{
			if (do_it_at_redirection(l_token, l_parsing) == NULL)
				return (NULL);
			l_token = l_token->next;
		}
		else
		{
			if (do_it_at_pipe(l_token, l_parsing) == NULL)
				return (NULL);
			l_parsing = l_parsing->next;
		}
		l_token = l_token->next;
	}
	return (head);
}
