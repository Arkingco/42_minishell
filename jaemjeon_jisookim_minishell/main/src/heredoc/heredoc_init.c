/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 02:34:05 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_hdoc(t_exec *exec, t_hdoc *hdoc) // count all of the heredocs.
{
	int		count;
	t_cmd	*cmd;

	count = 0;
	cmd = get_cmd_for_index(exec, 0);
	while (cmd) // need to fix init problem
	{
		while (cmd->redirect_input) // 같은 cmd에서 히어독 카운트
		{
			if (cmd->redirect_input->type & HEREDOC)
				count++;
			if (!cmd->redirect_input->next)
			{
				cmd->redirect_input = reset_redi_input(cmd);
				break;
			}
			else
				cmd->redirect_input = cmd->redirect_input->next;
		}
		if (cmd && !cmd->next)
			break ;
		else
			cmd = cmd->next;
	}
	hdoc->count = count;
	return ;
}

void	make_heredoc_lilmiter_array(t_exec *exec, t_hdoc *hdoc)
{
	int		i;
	t_cmd 	*cmd;

	i = 0;
	cmd = get_cmd_for_index(exec, 0);

	while (cmd)
	{
		//debug_print_lst_cmd(cmd);
		while (cmd->redirect_input) // 같은 cmd에서 히어독 카운트
		{
			if (cmd->redirect_input->type & HEREDOC)
			{
				hdoc->limiters[i] = ft_strdup(cmd->redirect_input->string_value);
				i++;
			}
			if (!cmd->redirect_input->next)
			{
				cmd->redirect_input = reset_redi_input(cmd);
				break;
			}
			else
				cmd->redirect_input = cmd->redirect_input->next;
		}
		if (cmd && !cmd->next)
			break ;
		else
			cmd = cmd->next;
	}
}


int	init_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc)
{
	t_cmd 	*cmd;

	count_hdoc(exec, hdoc);
	if (!hdoc->count)
		return (0);

	hdoc->limiters = (char **)safe_calloc(hdoc->count, sizeof(char *));
	hdoc->limiter_fds = (int *)safe_calloc(hdoc->count, sizeof(int));
	hdoc->hdoc_pids = (pid_t *)safe_calloc(hdoc->count, sizeof(int *));

	make_heredoc_lilmiter_array(exec, hdoc);
	
	return (1);
}
