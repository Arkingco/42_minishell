/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_make_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:45:54 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/23 22:29:18 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_input_token_in_cmd(t_cmd *cmd, t_token **token)
{
	t_token	*cur_token;

	cur_token = *token;
	if (cur_token->type == E_REDIRECT)
	{
		cur_token->next->redirect_type = cur_token->redirect_type;
		if (cur_token->redirect_type == E_REDI_L || \
				cur_token->redirect_type == E_REDI_LL)
		{
			ft_token_lstadd_back(&(cmd->redirect.unused_token), cur_token);
			cur_token = cur_token->next;
			ft_token_lstadd_back(&(cmd->redirect.redirect_input), cur_token);
		}
		else
		{
			ft_token_lstadd_back(&(cmd->redirect.unused_token), cur_token);
			cur_token = cur_token->next;
			ft_token_lstadd_back(&(cmd->redirect.redirect_output), cur_token);
		}
		return (2);
	}
	else
		ft_token_lstadd_back(&(cmd->simple_command), token);
	return (1);
}

void	ft_make_one_cmd(t_cmd **result, t_token **start_token)
{
	t_cmd	*new_cmd;
	t_token	*cur_token;
	int		token_count_toskip;

	new_cmd = ft_calloc(1, sizeof(t_cmd));
	cur_token = *start_token;
	if (new_cmd == NULL)
		ft_error(1, "malloc failed in ft_calloc in ft_make_one_cmd");
	while (cur_token != NULL && cur_token->type != E_PIPE)
	{
		token_count_toskip = ft_input_token_in_cmd(new_cmd, &cur_token);
		while (token_count_toskip--)
			cur_token = cur_token->next;
	}
	if (cur_token == NULL)
		*start_token = NULL;
	else if (cur_token->type == E_PIPE)
		*start_token = cur_token->next;
	*result = new_cmd;
}

t_cmd	*make_cmd_list(t_token *lst_token)
{
	t_token	*cur_token;
	t_cmd	*new_cmd;
	t_cmd	*lst_cmd;
	int		count_read_token;

	lst_cmd = NULL;
	cur_token = lst_token;
	if (cur_token == NULL)
		return (NULL);
	while (cur_token != NULL)
	{
		ft_make_one_cmd(&new_cmd, &cur_token);
		ft_cmd_lstadd_back(&lst_cmd, new_cmd);
	}
	return (lst_cmd);
}
