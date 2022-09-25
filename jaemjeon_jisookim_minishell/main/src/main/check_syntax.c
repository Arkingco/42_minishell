/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:41:58 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 15:28:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_syntax_quote(char *line)
{
	while (*line != '\0')
	{
		if (*line == '\'')
		{
			line = ft_strchr(line + 1, '\'');
			if (line == NULL)
				return (FALSE);
		}
		else if (*line == '\"')
		{
			line = ft_strchr(line + 1, '\"');
			if (line == NULL)
				return (FALSE);
		}
		line++;
	}
	return (TRUE);
}

void	check_redirection_grammar(t_token *lst_token)
{
	if (lst_token->prev != NULL &&
		(lst_token->prev->type & PIPE || lst_token->prev->type & REDIRECT))
	{
		if (lst_token->type & WRITE)
			process_errno(258, ">", SYNTAX_ERR);
		else if (lst_token->type & WRITE_APPEND)
			process_errno(258, ">>", SYNTAX_ERR);
		else if (lst_token->type & READ)
			process_errno(258, "<", SYNTAX_ERR);
		else if (lst_token->type & HEREDOC)
			process_errno(258, "<<", SYNTAX_ERR);
	}
	else
		process_errno(258, "newline", SYNTAX_ERR);
}

int	check_syntax_grammar(t_token *lst_token)
{
	while (lst_token != NULL)
	{
		if (is_error_token(lst_token))
		{
			if (lst_token->type & PIPE)
				process_errno(258, "|", SYNTAX_ERR);
			if (lst_token->type & REDIRECT)
			{
				check_redirection_grammar(lst_token);
			}
			return (TRUE);
		}
		lst_token = lst_token->next;
	}
	return (FALSE);
}
