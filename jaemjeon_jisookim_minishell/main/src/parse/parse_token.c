/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:21:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/19 16:50:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	parse_add_word_token(t_token *token_addr)
{
	t_simple_command *word;

	word = &g_global.lst_cmd->simple_command;
	token_addr->next = NULL;
	ft_token_lstadd_back(&word, token_addr);
}

