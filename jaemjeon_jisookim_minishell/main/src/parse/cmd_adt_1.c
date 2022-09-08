/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_adt_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:36:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 14:47:57 by jaemjeon         ###   ########.fr       */
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

void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd->simple_cmd != NULL)
		ft_free_tokenlst(cmd->simple_cmd);
	if (cmd->redirect_input != NULL)
		ft_free_tokenlst(cmd->redirect_input);
	if (cmd->redirect_output != NULL)
		ft_free_tokenlst(cmd->redirect_output);
	free(cmd);
}

void	ft_free_cmdlst(t_cmd *cmd)
{
	t_cmd	*cur_cmd;
	t_cmd	*next_cmd;

	cur_cmd = cmd;
	while (1)
	{
		next_cmd = cur_cmd->next;
		ft_free_cmd(cur_cmd);
		cur_cmd = next_cmd;
		if (cur_cmd == NULL)
			return ;
	}
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
