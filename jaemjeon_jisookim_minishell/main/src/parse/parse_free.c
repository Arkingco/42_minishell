/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:30:47 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 14:44:16 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd->simple_cmd != NULL)
		ft_free_tokenlst(cmd->simple_cmd);
	if (cmd->redirect_input != NULL)
		ft_free_tokenlst(cmd->redirect_input);
	if (cmd->redirect_output != NULL)
		ft_free_tokenlst(cmd->redirect_output);
	free(cmd);
}

void	ft_free_cmdlst(t_cmd *cmd)
{
	t_cmd	*cur_cmd;
	t_cmd	*next_cmd;

	cur_cmd = cmd;
	while (1)
	{
		next_cmd = cur_cmd->next;
		ft_free_cmd(cur_cmd);
		cur_cmd = next_cmd;
		if (cur_cmd == NULL)
			return ;
	}
}
