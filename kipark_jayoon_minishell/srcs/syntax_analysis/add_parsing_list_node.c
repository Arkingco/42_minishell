/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_parsing_list_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:45:12 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 21:45:39 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_parsing_list_node(t_parsing_list *l_parsing, t_parsing_list *node)
{
	l_parsing->next = node;
}
