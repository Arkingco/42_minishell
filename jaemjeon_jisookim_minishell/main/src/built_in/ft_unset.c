/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 04:52:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_cmd *cmd, t_envlst *env)
{
	t_token *cmd_argv;

	cmd_argv = cmd->simple_cmd->next;
	while (cmd_argv != NULL)
}
