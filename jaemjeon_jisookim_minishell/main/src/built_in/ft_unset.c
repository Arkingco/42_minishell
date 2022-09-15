/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/15 15:20:33 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_cmd *cmd, t_working_info *info)
{
	t_token	*to_unset_token;

	to_unset_token = cmd->simple_cmd->next;
	while (to_unset_token != NULL)
	{
		ft_delenv(&info->env,to_unset_token->string_value);
		to_unset_token = to_unset_token->next;
	}
}
