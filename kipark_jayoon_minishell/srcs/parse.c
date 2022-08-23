/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:36:24 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/23 11:15:13 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdio.h>

static int	get_quote_type_return_index(char *rl, int i, \
												t_token_type this_token_type)
{
	if (this_token_type == T_SINGLE_QUOTE)
		while (rl[i] != M_SINGLE_QUOTE && rl[i + 1] != '\0')
		{
			++i;
		}
	else if (this_token_type == T_DOUBLE_QUOTE && rl[i + 1] != '\0')
		while (rl[i] != M_DOUBLE_QUOTE && rl[i + 1] != '\0')
			++i;
	return (i);
}

static int	set_token_type_return_index(char *rl, int i, \
							t_token_type this_token_type, t_token_type *t_type)
{
	*t_type = this_token_type;
	if (this_token_type == T_WORD)
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

static void	read_readline(char *rl, t_token *token_head)
{
	int				start;
	int				end;
	t_token_type	t_type;

	start = 0;
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
		token_add(token_head, t_type, ft_substr(rl, start, end - start + 1));		
		end++;
	}
	if (rl[end] == '\0')
		token_add(token_head, t_type, (char *)T_NULL);
}

t_token	*tokenize(char *readline)
{
	t_token *token_head;

	token_head = malloc(sizeof(t_token));
	if (token_head == NULL)
		return (NULL);
	init_token_dummy_node(token_head);
	if (check_readline_able_parse(readline))
	{
		printf("syntex error\n");
		return (NULL);
	}
	read_readline(readline, token_head);
	// token_extention(token_head);
	print_token_list(token_head);
	return (token_head);
}
