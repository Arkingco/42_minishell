/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:23:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/02 14:24:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void	init_redir_iter(t_parsing_list *l_parsing)
{
	l_parsing->redir_iter 
		= (t_redir_iter *)ft_safe_malloc(sizeof(t_redir_iter));
	l_parsing->redir_iter->l_input = NULL;
	l_parsing->redir_iter->l_output = NULL;
}
