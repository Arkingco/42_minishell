/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_and_set_parsing_list.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:43:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 22:08:51 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

static void	do_it_at_word(void)
{
}
static void	do_it_at_redirection(void)
{
}
static void	do_it_at_pipe(void)
{
}

void	check_syntax_and_set_parsing_list(t_token *l_token, \
				t_parsing_list *l_parsing)
{
	void	*node;

	l_token = l_token->next;
	// l_token 은 토큰을 사용하는데 처음이 NULL일 수 있나?
	if (!l_token && l_token->type == T_PIPE)
		return ((t_parsing_list *)print_syntax_error_pipe());
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
			node = init_redirection_node(l_token->str, l_token->next->str);
			if (l_token->type == T_INPUT_REDIR || l_token->type == T_HERE_DOC)
				add_redir_chunk_node(&l_parsing->redir_iter->l_input,
					(t_redir_chunk *)node);
			else
				add_redir_chunk_node(&l_parsing->redir_iter->l_output,
					(t_redir_chunk *)node);
		}
		else
		{
			node = init_parsing_list();
			add_parsing_list_node(l_parsing, (t_parsing_list *)node);
			l_parsing = l_parsing->next;
		}
		l_token = l_token->next;
	}
}
