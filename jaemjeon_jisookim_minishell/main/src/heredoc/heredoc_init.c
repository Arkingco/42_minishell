/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 15:41:31 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	make_delimiter_array(t_cmd *cmd, t_hdoc *hdoc)
{
	int	i;

	i = 0;
	while (cmd && cmd->redirect_input)
	{
		if (cmd->redirect_input->type & HEREDOC)
		{
			hdoc->delimiter_arr[i] = cmd->redirect_input->string_value;
			cmd = cmd->next;
			i++;
		}
		cmd = cmd->next;
	}
}
