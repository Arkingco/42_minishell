/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:36:24 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 17:12:28 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "env.h"
#include "error.h"
#include "lexer.h"
#include <stdio.h>

int	get_quote_type_return_index(char *rl, int i, \
												t_token_type this_token_type)
{
	if (this_token_type == T_SINGLE_QUOTE)
	{
		while (rl[i] != M_SINGLE_QUOTE && rl[i + 1] != '\0')
		{
			++i;
		}
	}
	else if (this_token_type == T_DOUBLE_QUOTE && rl[i + 1] != '\0')
	{
		while (rl[i] != M_DOUBLE_QUOTE && rl[i + 1] != '\0')
			++i;
	}
	return (i);
}

static int	set_token_type_return_index(char *rl, int i, \
							t_token_type this_token_type, t_token_type *t_type)
{
	*t_type = this_token_type;
	if (this_token_type == T_WORD)
	{
		while (rl[i + 1] != '\0')
		{
			if (rl[i] == M_SINGLE_QUOTE)
				i = get_quote_type_return_index(rl, i + 1, T_SINGLE_QUOTE);
			else if (rl[i] == M_DOUBLE_QUOTE)
				i = get_quote_type_return_index(rl, i + 1, T_DOUBLE_QUOTE);
			if (ft_isifs(rl[i + 1]) || \
				is_metachar_not_include_quote(rl[i + 1]) || rl[i + 1] == '\0')
				return (i);
			++i;
		}
	}
	else if (this_token_type == T_INPUT_REDIR || this_token_type == \
		T_OUTPUT_REDIR || this_token_type == T_PIPE)
		i = i + 0;
	else if (this_token_type == T_HERE_DOC || this_token_type == \
		T_APPEND_REDIR)
		i = i + 1;
	return (i);
}

static int	set_meta_token_type_return_end_index(char *rl, int i, \
														t_token_type *t_type)
{
	if (rl[i] == M_INPUT_REDIR)
	{
		if (rl[i + 1] == M_INPUT_REDIR)
			return (set_token_type_return_index(rl, i, T_HERE_DOC, t_type));
		else
			return (set_token_type_return_index(rl, i, T_INPUT_REDIR, t_type));
	}
	else if (rl[i] == M_OUTPUT_REDIR)
	{
		if (rl[i + 1] == M_OUTPUT_REDIR)
			return (set_token_type_return_index(rl, i, T_APPEND_REDIR, t_type));
		else
			return (set_token_type_return_index(rl, i, T_OUTPUT_REDIR, t_type));
	}
	else if (rl[i] == M_PIPE)
		return (set_token_type_return_index(rl, i, T_PIPE, t_type));
	return (i);
}

static void	read_readline(t_env *env_head, char *rl, t_token *token_head)
{
	int				start;
	int				end;
	t_token_type	t_type;

	end = 0;
	t_type = T_NULL;
	while (rl[end] != '\0')
	{
		end = pass_ifs(rl, end);
		if (rl[end] == '\0')
			break ;
		start = end;
		if (is_metachar_not_include_quote(rl[end]))
			end = set_meta_token_type_return_end_index(rl, end, &t_type);
		else
			end = set_token_type_return_index(rl, end, T_WORD, &t_type);
		if (t_type == T_WORD)
			word_token_add(token_head, t_type, \
				expand_this_word_token(env_head, \
								ft_safe_substr(rl, start, end - start + 1)));
		else
			token_add(token_head, t_type, \
								ft_safe_substr(rl, start, end - start + 1));
		end++;
	}
}

t_token	*tokenize(t_env *env_head, char *readline)
{
	t_token	*token_head;

	token_head = ft_safe_malloc(sizeof(t_token));
	init_token_dummy_node(token_head);
	if (check_readline_quote_close(readline))
	{
		token_free(token_head);
		print_quote_error();
		return (NULL);
	}
	read_readline(env_head, readline, token_head);
	remove_quote(token_head);
	return (token_head);
}
