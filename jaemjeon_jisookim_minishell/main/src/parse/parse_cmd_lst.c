/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:36:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 14:46:32 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*ft_cmd_lst_first(t_cmd *cmd_lst)
{
	t_cmd	*first_cmd;

	first_cmd = cmd_lst;
	while (first_cmd->prev != NULL)
		first_cmd = first_cmd->prev;
	return (first_cmd);
}

t_cmd	*make_cmd_linkedlst(t_token *token_lst)
{
	t_cmd	*cur_cmd;
	t_cmd	*first_cmd;

	first_cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	cur_cmd = first_cmd;
	while (token_lst != NULL)
	{
		if (token_lst->type & PIPE)
		{
			cur_cmd->next = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
			cur_cmd = cur_cmd->next;
		}
		token_lst = token_lst->next;
	}
	return (first_cmd);
}

int	ft_cmdlst_size(t_cmd *cmd)
{
	int	size;

	size = 0;
	while (cmd != NULL)
	{
		size++;
		cmd = cmd->next;
	}
	return (size);
}
