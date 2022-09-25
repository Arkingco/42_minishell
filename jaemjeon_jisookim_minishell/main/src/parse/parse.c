/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:33:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 23:19:00 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	combine_redirect_filename(t_token *token_lst)
{
	t_token	*cur_token;

	cur_token = token_lst;
	while (cur_token != NULL && cur_token->next != NULL)
	{
		if (cur_token->type & REDIRECT)
		{
			cur_token->string_value = ft_strdup(cur_token->next->string_value);
			if (cur_token->string_value == NULL)
				ft_error_exit(1, "malloc failed in ft_strdup in combine_token");
			cur_token->type |= cur_token->next->type & QUOTE;
			ft_deltoken(&cur_token->next);
		}
		cur_token = cur_token->next;
	}
}

void	check_cur_token_type(t_token *cur_token, t_cmd **cur_cmd)
{
	if (cur_token->type & PIPE)
	{
		*cur_cmd = (*cur_cmd)->next;
		ft_free_token(cur_token);
	}
	else if (cur_token->type & REDIRECT)
	{
		if (cur_token->type & (READ | HEREDOC))
			ft_token_lstadd_back(&(*cur_cmd)->redirect_input, cur_token);
		else
			ft_token_lstadd_back(&(*cur_cmd)->redirect_output, cur_token);
	}
	else
		ft_token_lstadd_back(&(*cur_cmd)->simple_cmd, cur_token);
}

t_cmd	*token_to_cmd(t_token *token_lst)
{
	t_token	*cur_token;
	t_token	*next_token;
	t_cmd	*cur_cmd;
	t_cmd	*first_cmd;

	cur_token = token_lst;
	first_cmd = make_cmd_linkedlst(token_lst);
	cur_cmd = first_cmd;
	while (cur_token != NULL)
	{
		next_token = cur_token->next;
		check_cur_token_type(cur_token, &cur_cmd);
		cur_token = next_token;
	}
	return (first_cmd);
}
