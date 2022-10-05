/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:05:31 by kipark            #+#    #+#             */
/*   Updated: 2022/10/05 21:09:39 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_metachar_not_include_quote(char c)
{
	if (c == M_INPUT_REDIR || c == M_OUTPUT_REDIR || c == M_PIPE)
		return (1);
	return (0);
}

int	ft_isifs(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

void	pass_sigle_quote(char *str, int *i)
{
	while (str[*i + 1] != M_SINGLE_QUOTE)
		++(*i);
	++(*i);
}

int	pass_ifs(char *rl, int i)
{
	while (ft_isifs(rl[i]) && rl[i] != '\0')
		++i;
	return (i);
}

int	check_readline_quote_close(char *rl)
{
	int	i;
	int	type;

	i = 0;
	while (rl[i] != '\0')
	{
		if (rl[i] == M_SINGLE_QUOTE || rl[i] == M_DOUBLE_QUOTE)
		{
			type = rl[i];
			i++;
			while (rl[i] != '\0' && rl[i] != type)
				i++;
		}
		if (rl[i] == '\0')
			return (1);
		++i;
	}
	return (0);
}
