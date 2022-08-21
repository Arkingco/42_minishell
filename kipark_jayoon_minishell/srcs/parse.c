/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:36:24 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/21 16:30:48 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdio.h>

int	is_metacharacter_not_include_quote(char c)
{
	if (c == M_INPUT_REDIR || c == M_OUTPUT_REDIR || c == M_PIPE)
		return (1);
	return (0);
}

int	is_metacharacter(char c)
{
	if (c == M_DOUBLE_QUOTE || c == M_SINGLE_QUOTE || c == M_INPUT_REDIR || \
		c == M_OUTPUT_REDIR || c == M_PIPE)
		return (1);
	return (0);
}

int	ft_isifs(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}


static int	pass_ifs(char *rl, int i)
{
	while (ft_isifs(rl[i]) && rl[i] != '\0')
		++i;
	return (i);
}

static int	get_quote_type_return_index(char *rl, int i, \
	t_token_type this_token_type)
{
	if (this_token_type == T_SINGLE_QUOTE)
		while (rl[i] != M_SINGLE_QUOTE)
			++i;
	else if (this_token_type == T_DOUBLE_QUOTE)
		while (rl[i] != M_DOUBLE_QUOTE)
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
			if (rl[i + 1] == M_SINGLE_QUOTE)
				i = get_quote_type_return_index(rl, i + 1, T_SINGLE_QUOTE);
			else if (rl[i + 1] == M_DOUBLE_QUOTE)
				i = get_quote_type_return_index(rl, i + 1, T_DOUBLE_QUOTE);
			if (ft_isifs(rl[i + 1]) || is_metacharacter_not_include_quote(rl[i + 1]) || rl[i + 1] == '\0')
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

static int	set_meta_token_type_return_end_index(char *rl, int i, t_token_type *t_type)
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
	int				i;
	t_token_type	t_type;

	start = 0;
	i = 0;
	t_type = T_NULL;
	while (rl[i] != '\0')
	{
		i = pass_ifs(rl, i);
		start = i;
		if (is_metacharacter_not_include_quote(rl[i]))
			i = set_meta_token_type_return_end_index(rl, i, &t_type);
		else
			i = set_token_type_return_index(rl, i, T_WORD, &t_type);
		token_add_list(token_head, t_type, ft_substr(rl, start, i - start + 1));		
		i++;
	}
	if (rl[i] == '\0')
		token_add_list(token_head, t_type, (char *)T_NULL);
}

t_token	*tokenize(char *readline)
{
	t_token *token_head;

	token_head = malloc(sizeof(t_token));
	if (token_head == NULL)
		printf("malloc Errror \n");
	init_token_dummy_node(token_head);
	read_readline(readline, token_head);
	print_token_list(token_head);
	return (token_head);
}