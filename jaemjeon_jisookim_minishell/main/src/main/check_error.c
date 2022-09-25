/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:40:02 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 20:32:55 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "minishell: too many arguments");
}

int	check_err_token_prev(t_token *suspect_token)
{
	if (suspect_token->prev->type & REDIRECT)
	{
		if (!(suspect_token->type & WORD))
			return (TRUE);
		return (FALSE);
	}
	else if (suspect_token->prev->type & PIPE)
	{
		if (suspect_token->type & PIPE)
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}

int	is_error_token(t_token *suspect_token)
{
	if (suspect_token->prev == NULL && suspect_token->next == NULL)
	{
		if (!(suspect_token->type & WORD))
			return (TRUE);
		return (FALSE);
	}
	else if (suspect_token->prev == NULL)
	{
		if (suspect_token->type & PIPE)
			return (TRUE);
		return (FALSE);
	}
	else if (suspect_token->next == NULL)
	{
		if (!(suspect_token->type & WORD))
			return (TRUE);
	}
	else
		return (check_err_token_prev(suspect_token));
	return (FALSE);
}
