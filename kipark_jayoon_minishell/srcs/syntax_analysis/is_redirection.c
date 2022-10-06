/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:19:27 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:21:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_redirection(t_token_type type)
{
	if (type == T_INPUT_REDIR || type == T_HERE_DOC
		|| type == T_OUTPUT_REDIR || type == T_APPEND_REDIR)
		return (1);
	return (0);
}
