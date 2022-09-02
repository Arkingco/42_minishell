/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:36:24 by kipark            #+#    #+#             */
/*   Updated: 2022/09/02 14:07:01 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

void	free_all(char *line, t_token *token, t_parsing_list *l_parsing)
{
	free(line);
	line = NULL;
	token_free(token);
	free_parsing_list(l_parsing);
}
