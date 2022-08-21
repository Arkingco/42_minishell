/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:05:31 by kipark            #+#    #+#             */
/*   Updated: 2022/08/21 18:08:03 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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


int	pass_ifs(char *rl, int i)
{
	while (ft_isifs(rl[i]) && rl[i] != '\0')
		++i;
	return (i);
}