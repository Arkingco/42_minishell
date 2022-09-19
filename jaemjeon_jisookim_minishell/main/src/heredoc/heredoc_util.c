/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:44:26 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 03:08:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_heredoc(t_working_info *info)
{
	t_cmd	*cur_cmd;
	t_token	*cur_input_redirection;

	cur_cmd = info->cmd;
	while (cur_cmd != NULL)
	{
		cur_input_redirection = cur_cmd->redirect_input;
		while (cur_input_redirection != NULL)
		{
			if (cur_input_redirection->type & HEREDOC)
				return (TRUE);
			cur_input_redirection = cur_input_redirection->next;
		}
		cur_cmd = cur_cmd->next;
	}
	return (FALSE);
}