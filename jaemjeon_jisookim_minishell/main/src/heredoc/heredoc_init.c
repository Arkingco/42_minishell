/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 17:47:37 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	make_heredoc_lilmiter_array(t_exec *exec, t_hdoc *hdoc)
{
	int		i;
	int		len;
	t_cmd 	*cmd;

	i = 0;
	cmd = get_cmd_for_index(exec, 0);
	while (cmd && cmd->redirect_input)
	{
		if (cmd->redirect_input->type & HEREDOC)
		{
			hdoc->limiters[i] = ft_strdup(cmd->redirect_input->string_value);
			cmd = cmd->next;
			i++;
		}
		cmd = cmd->next;
	}
}
