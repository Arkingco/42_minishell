/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:36:24 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 16:52:27 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

int	return_end_index(char *str, int i)
{
	
}

int	is_metacharacter(char c)
{
	if (c == M_DOUBLE_QUOTE || c == M_SINGLE_QUOTE || c == M_INPUT_REDIRECTION || \
		c == M_OUTPUT_REDIRECTION || c == M_PIPE)
		return (1);
	return (0);
}

static int	pass_ifs(char *readline, int i)
{
	while (ft_isspace(readline[i]) && readline[i])
		++i;
	return (i);
}

static int	get_token_type(char *str, int i, t_token_type *t_type)
{
	if (str[i] == M_DOUBLE_QUOTE)
		t_type = T_DOUBLE_QUOTE;
	else if (str[i] == M_SINGLE_QUOTE)
	{
		t_type = M_SINGLE_QUOTE;
		while (str[i + 1] != M_SINGLE_QUOTE)
		{
			
		}
	}
	else if (str[i] == M_INPUT_REDIRECTION)
	{
		t_type = M_INPUT_REDIRECTION;
	}
	else if (str[i] == M_OUTPUT_REDIRECTION)
	{
		t_type = M_OUTPUT_REDIRECTION;
	}
	else if (str[i] == M_PIPE)
	{
		t_type = M_PIPE;
	}
}

void	read_readline(char *readline)
{
	int				start;
	int				i;
	t_token_type	t_type;

	start = 0;
	i = 0;
	while (readline[i] != '\0')
	{
		start = pass_ifs(readline, i);
		if (is_metacharacter(readline[i]))
			get_token_type(readline, i, &t_type);
		else
		{
			i = get_word_token_end_index(readline, i)
			i++;
		}
		if (ft_isspace(readline[i + 1]))
			token_add_list(set_token ,ft_substr(readline, start, i));
	}
}

void	*tokenize(char *readline)
{
	read_readline()
}
