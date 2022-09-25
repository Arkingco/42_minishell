/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:07:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 22:04:03 by kipark           ###   ########seoul.kr  */
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
	if (l_parsing->l_simple_cmd)
		free_simple_cmd_list(l_parsing->l_simple_cmd);
	if (l_parsing->redir_iter)
	{
		if (l_parsing->redir_iter->l_input)
			free_redir_chunk_list(l_parsing->redir_iter->l_input);
		if (l_parsing->redir_iter->l_output)
			free_redir_chunk_list(l_parsing->redir_iter->l_output);
		free(l_parsing->redir_iter);
	}
	free(l_parsing);
	l_parsing = NULL;
}
