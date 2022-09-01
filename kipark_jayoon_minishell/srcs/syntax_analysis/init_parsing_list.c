/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:46:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/01 14:15:04 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static void	init_simple_cmd(t_simple_cmd *l_simple_cmd)
{
	l_simple_cmd = ft_safe_malloc(sizeof(t_simple_cmd));
	l_simple_cmd->str = NULL;
	l_simple_cmd->next = NULL;
}

static void	init_redir_iter(t_redir_iter *redir_iter)
{
	redir_iter = ft_safe_malloc(sizeof(t_redir_iter));
	init_redir_chunk(redir_iter->l_input);
	init_redir_chunk(redir_iter->l_output);
}

static void	init_redir_chunk(t_redir_chunk *chunk)
{
	chunk = ft_safe_malloc(sizeof(t_redir_chunk));
	chunk->redir = NULL;
	chunk->file_name = NULL;
	chunk->next = NULL;
}

void	init_parsing_list(t_parsing_list *l_parsing)
{
	init_simple_cmd(l_parsing->l_simple_cmd);
	init_redir_iter(l_parsing->redir_iter);
	l_parsing->next = NULL;
}
