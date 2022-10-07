/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 20:24:10 by kipark           ###   ########seoul.kr  */
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
		return (print_syntax_error());
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
		return (print_syntax_error());
	node = init_parsing_list();
	add_parsing_list_node(l_parsing, (t_parsing_list *)node);
	return (node);
}

static int	create_parsing_list(t_parsing_list *l_parsing, t_token *l_token)
{
	while (l_token)
	{
		if (is_word(l_token->type))
			do_it_at_word(l_token, l_parsing);
		else if (is_redirection(l_token->type))
		{
			if (do_it_at_redirection(l_token, l_parsing) == NULL)
				return (0);
			l_token = l_token->next;
		}
		else
		{
			if (do_it_at_pipe(l_token, l_parsing) == NULL)
				return (0);
			l_parsing = l_parsing->next;
		}
		l_token = l_token->next;
	}
	return (1);
}

t_parsing_list	*parse_tokenized_data(t_token *l_token)
{
	t_parsing_list	*l_parsing;
	int				is_syntax_right;

	l_parsing = NULL;
	if (!l_token->next)
		return (NULL);
	if (l_token->next->type == T_PIPE)
		return (print_syntax_error());
	l_parsing = init_parsing_list();
	l_token = l_token->next;
	is_syntax_right = create_parsing_list(l_parsing, l_token);
	if (is_syntax_right == 0)
	{
		free_parsing_list(l_parsing);
		return (NULL);
	}
	return (l_parsing);
}
