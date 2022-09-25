/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:47:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 20:17:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

int	is_heredoc_delimiter_token(t_token *token)
{
	while (token->prev && token->type & WORD && token->prev->type & WORD && \
													token->type & LEFT_JOIN)
		token = token->prev;
	if (token->prev && token->prev->type & HEREDOC)
		return (TRUE);
	else
		return (FALSE);
}

void	expander(t_token **token_lst, t_envlst *env)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if (is_heredoc_delimiter_token(cur_token))
		{
			cur_token = cur_token->next;
			continue ;
		}
		if ((cur_token->type & WORD) && !(cur_token->type & SQUOTE))
		{
			expand_pidenv(cur_token);
			expand_env(cur_token, env);
		}
		cur_token = cur_token->next;
	}
}
