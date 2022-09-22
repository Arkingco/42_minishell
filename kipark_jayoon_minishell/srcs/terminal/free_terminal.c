/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:36:24 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 17:00:35 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

void	free_all(char *line, t_token *token, t_parsing_list *l_parsing)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	if (token != NULL)
	{
		token_free(token);
	}
	if (l_parsing != NULL)
	{
		free_parsing_list(l_parsing);
	}
}
