/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_chunk_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:48:21 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 21:49:12 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

void	add_redir_chunk_node(t_redir_chunk **head, t_redir_chunk *node)
{
	t_redir_chunk	*last;

	if (*head == NULL)
		*head = node;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}
