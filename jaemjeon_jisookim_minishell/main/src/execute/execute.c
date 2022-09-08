/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 15:16:30 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_single_cmd(t_cmd *cmd, t_envlst *env)
{

}

void	process_multi_cmd(t_cmd *cmd, t_envlst *env)
{

}

void	execute(t_cmd *cmd, t_envlst *env)
{
	int	cmd_count;

	cmd_count = ft_cmdlst_size(cmd);
	if (cmd_count == 0)
		return ;
	else if (cmd_count == 1)
	{
		process_single_cmd(cmd, env);
	}
	else
	{
		process_multi_cmd(cmd, env);
	}
}
