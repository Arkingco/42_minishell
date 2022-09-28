/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 22:44:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

int	ft_unset(t_cmd *cmd, t_working_info *info)
{
	t_token	*to_unset_token;

	to_unset_token = cmd->simple_cmd->next;
	while (to_unset_token != NULL)
	{
		if (check_key_grammar(to_unset_token->string_value))
			process_errno(1, to_unset_token->string_value, IDENTIFIER_ERR);
		ft_delenv(&info->env, to_unset_token->string_value);
		to_unset_token = to_unset_token->next;
	}
	return (0);
}
