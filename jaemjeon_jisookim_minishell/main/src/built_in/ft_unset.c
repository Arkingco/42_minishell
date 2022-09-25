/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 20:11:44 by jaemjeon         ###   ########.fr       */
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
		if (ft_delenv(&info->env, to_unset_token->string_value) == FALSE)
			return (1);
		to_unset_token = to_unset_token->next;
	}
	return (0);
}
