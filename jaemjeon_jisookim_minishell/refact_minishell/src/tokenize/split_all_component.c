/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_all_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 06:10:38 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 06:33:39 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	ft_get_token_type(t_readstate *readstate)
{
	unsigned int	result_flag;

	result_flag = 0;
	if (readstate->state & PIPE)
		return (PIPE);
	else if (readstate->state & REDIRECT)
}

t_token	*split_all_component(char *line)
{
	t_token		*lst_token;
	t_readstate	readstate;
	int			index;

	lst_token = NULL;
	ft_reset_readstate(&readstate);
	index = 0;
	while (line[index] != '\0')
	{
		if (readstate.state & QUOTE)
			read_in_quote(line[index])
		else if (line[index] == '<' || line[index] == '>')
		{

		}
	}
}