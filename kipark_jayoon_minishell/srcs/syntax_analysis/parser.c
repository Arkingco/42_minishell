/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/19 21:36:10 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	typedef enum e_token_type
	{
		T_NULL,
		T_WORD,
		T_DOUBLE_QUOTE,
		T_SINGLE_QUOTE,
		T_INPUT_REDIR,
		T_HERE_DOC,
		T_OUTPUT_REDIR,
		T_APPEND_REDIR,
		T_PIPE
	}	t_token_type;

	typedef struct s_token
	{
		t_token_type	type;
		char			*str;
		struct s_token	*next;
	}	t_token;

문법 검사
	토큰 타입과 문자열을 가지고 있는 dummy linked list 를 하나씩 탐색하며 검사함
	(처음 노드인 T_NULL 은 뛰어 넘어야 함)
		처음에 올 수 있는 타입은
			T_WORD
			T_INPUT_REDIR
			T_HERE_DOC
			T_OUTPUT_REDIR
			T_APPEND_REDIR
		올 수 없는 타입은
			T_PIPE
	
*/
/*
parser 가 해야 할 일은 
토큰화 된 데이터를 분석하여 문법이 맞는지 검사하며,
확인 된 노드들을 parsing linked list 에 넣는다.
parsing linked list 는 이후에 command program 을 실행하기 위해 사용하게 된다.
*/

#include "error.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

/* ft_safe_malloc */
#include "libft.h"

/*
*	print parsing list
*/
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

static t_redir_chunk	*init_redirection_node(char *str_redir,
							char *str_file_name)
{
	t_redir_chunk	*new;

	new = (t_redir_chunk *)ft_safe_malloc(sizeof(t_redir_chunk));
	new->redir = str_redir;
	new->file_name = str_file_name;
	new->next = NULL;
	return (new);
}

static void	add_redir_chunk_node(t_redir_chunk **head, t_redir_chunk *node)
{
	t_redir_chunk	*last;

	if (*head == NULL)
		*head = node;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}

t_parsing_list	*check_syntax_and_set_parsing_list(t_token *l_token, \
				t_parsing_list *l_parsing)
{
	void	*node;

	l_token = l_token->next;
	if (l_token && l_token->type == T_PIPE)
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
		// else // pipe
		// {
		// 	l_parsing node 만들고, next 에 연결
		// }
		l_token = l_token->next;
	}
	print_parsing_list(l_parsing);
	return (l_parsing);
}

t_parsing_list	*parser(t_token	*l_token)
{
	t_parsing_list	*l_parsing;

	l_parsing = init_parsing_list();
	l_parsing = check_syntax_and_set_parsing_list(l_token, l_parsing);
	return (l_parsing);
}
