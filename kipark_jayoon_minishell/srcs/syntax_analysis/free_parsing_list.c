/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:07:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/02 17:56:32 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

static void	free_simple_cmd_list(t_simple_cmd *head)
{
	t_simple_cmd	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
		temp = NULL;
	}
}
static void	free_redir_chunk_list(t_redir_chunk *head)
{
	t_redir_chunk	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
		temp = NULL;
	}
}

void	free_parsing_list(t_parsing_list *l_parsing)
{
	if (l_parsing == NULL)
		return ;
	free_simple_cmd_list(l_parsing->l_simple_cmd);
	free_redir_chunk_list(l_parsing->redir_iter.l_input);
	free_redir_chunk_list(l_parsing->redir_iter.l_output);
	free(l_parsing);
	l_parsing = NULL;
}
