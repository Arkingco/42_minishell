/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:40:02 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 15:45:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "too many arguments");
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
	}
	return (FALSE);
}

// int	is_error_token(t_token *suspect_token)
// {
// 	if (suspect_token->next == NULL)
// 	{
// 		if (suspect_token->type & REDIRECT)
// 			return (TRUE);
// 		else if (suspect_token->type & PIPE)
// 			return (TRUE);
// 		else
// 			return (FALSE);
// 	}
// 	if (suspect_token->prev == NULL)
// 	{
// 		if (suspect_token->type & PIPE)
// 			return (TRUE);
// 		else
// 			return (FALSE);
// 	}
// 	else
// 	{
// 		if (suspect_token->prev->type & REDIRECT)
// 		{
// 			if (!(suspect_token->type & WORD))
// 				return (TRUE);
// 		}
// 		else if (suspect_token->prev->type & PIPE)
// 		{
// 			if (suspect_token->type & PIPE)
// 				return (TRUE);
// 		}
// 	}
// 	return (FALSE);
// }

