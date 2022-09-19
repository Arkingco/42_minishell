/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:46:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/19 20:39:14 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_parsing_list	*init_parsing_list(void)
{
	t_parsing_list	*l_parsing;

	l_parsing = (t_parsing_list *)ft_safe_malloc(sizeof(t_parsing_list));
	l_parsing->l_simple_cmd = NULL;
	l_parsing->next = NULL;
	l_parsing->redir_iter 
		= (t_redir_iter *)ft_safe_malloc(sizeof(t_redir_iter));
	return (l_parsing);
}

/*
static t_parsing_list	*init_list(void)
{
	t_parsing_list	*l_parsing;

	l_parsing = ft_safe_malloc(sizeof(t_parsing_list));
	l_parsing->l_simple_cmd = NULL;
	l_parsing->redir_iter = NULL;
	l_parsing->next = NULL;
}

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
*/
