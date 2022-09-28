/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_all_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 06:10:38 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 12:36:42 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*split_all_component(char *line)
{
	t_token		*lst_token;
	t_token		*new_token;
	int			index;

	lst_token = NULL;
	index = 0;
	while (line[index] != '\0')
	{
		ft_skip_ifs2(line, &index);
		if (line[index] == '\0')
			break ;
		if (line[index] == '\"' || line[index] == '\'')
			new_token = read_in_quote(line, &index);
		else if (line[index] == '<' || line[index] == '>')
			new_token = read_in_redirect(line, &index);
		else if (line[index] == '|')
			new_token = read_in_pipe(line, &index);
		else
			new_token = read_in_pureword(line, &index);
		ft_token_lstadd_back(&lst_token, new_token);
	}
	return (lst_token);
}
