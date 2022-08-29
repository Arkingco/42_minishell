/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:33:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/29 22:00:55 by jaemjeon         ###   ########.fr       */
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

// t_cmd	*token_to_cmd(t_token *token_lst)
// {
// 	while (token_lst != NULL)
// 	{
// 		if (token_lst->type & PIPE)
// 		{

// 		}
// 		else if ()
// 	}
// }
