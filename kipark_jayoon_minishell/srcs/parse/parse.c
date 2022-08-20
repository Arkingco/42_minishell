/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:36:24 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/20 11:17:08 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

static int	get_word_token_end_index(char *readline, int i, t_metacharacter t_meta_type)
{
	if (t_meta_type == M_NOT) // word 받는 부분
	{
		while (!ft_isspace(readline[i]) && readline[i] != '\0')
			++i;
		return (i);
	}
	else					// 쿼터 받는 부분
	{
		while (readline[i] != t_meta_type)
			++i;
		return (i);
	}
	return (i);
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

static int	get_token_type_of_redirection_or_pipe(char *readline, int i, \
	t_metacharacter t_meta_type)
{

}
static int	get_token_type(char *readline, int i, t_token_type *t_type)
{
	int length;

	length = 0;
	if (readline[i] == M_DOUBLE_QUOTE)
	{
		*t_type = T_DOUBLE_QUOTE;
		return (get_word_token_end_index(readline, i, M_DOUBLE_QUOTE)); // ifs 신경 안쓰고 자기랑 같은 쿼터가 나올 때 까지 받아야함
	}
	else if (readline[i] == M_SINGLE_QUOTE)
	{
		*t_type = T_SINGLE_QUOTE;
		return (get_word_token_end_index(readline, i, M_SINGLE_QUOTE)); // ifs 신경 안쓰고 자기랑 같은 쿼터가 나올 때 까지 받아야함
	}
	else if (readline[i] == M_INPUT_REDIRECTION)
	{
		
		length = get_token_type_of_redirection_or_pipe;
		if (length == 1)
			*t_type = T_INPUT_REDIRECTION;
		if (length == 2)
			*t_type = T_APPEND_REDIRECTION;
	}
	else if (readline[i] == M_OUTPUT_REDIRECTION)
	{
		*t_type = M_OUTPUT_REDIRECTION;
	}
	else if (readline[i] == M_PIPE)
	{
		*t_type = M_PIPE;
	}
}

static void	read_readline(char *readline)
{
	int				start;
	int				i;
	t_token_type	t_type;

	start = 0;
	i = 0;
	while (readline[i] != '\0')
	{
		start = pass_ifs(readline, i);
		if (is_metacharacter(readline[i])) // | ' " > < >> <<
			i = get_token_type(readline, i, &t_type);
		else // words
			i = get_word_token_end_index(readline, i, M_NOT); // ifs 신경 쓰고 처리 해야함
		if (ft_isspace(readline[i + 1]))
			token_add_list(token_head ,ft_substr(readline, start, i));
	}
}

void	*tokenize(char *readline)
{
	read_readline(readline);
}
