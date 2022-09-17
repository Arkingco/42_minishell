/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 13:43:04 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_hdoc(t_exec *exec, t_hdoc *hdoc) // count all of the heredocs.
{
	int		count;
	t_cmd 	*cmd;

	count = 0;
	cmd = get_cmd_for_index(exec, 0);
	while (cmd) // need to fix init problem
	{
		while (cmd->redirect_input) // 같은 cmd에서 히어독 카운트
		{
			if (cmd->redirect_input->type & HEREDOC)
				count++;
			if (!cmd->redirect_input->next)
				break;
			else
				cmd->redirect_input = cmd->redirect_input->next;
		}
		if (cmd && !cmd->next)
			break ;
		else
			cmd = cmd->next;
	}
	hdoc->count = count;
	dprintf(2, "hdoc->count : %d\n", hdoc->count);
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
				break;
			else
				cmd->redirect_input = cmd->redirect_input->next;
		}
		if (cmd && !cmd->next)
			break ;
		else
			cmd = cmd->next;
	}
	//debug
	int j = 0;
	while (j < i)
	{
		dprintf(2, "hdoc->limiters[%d] : %s\n", j, hdoc->limiters[j]);
		j++;
	}
	return ;
}


int	init_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc)
{
	count_hdoc(exec, hdoc); // <- init problem
	if (!hdoc->count)
		return (0);
	
	hdoc->limiters = (char **)safe_calloc(hdoc->count, sizeof(char *));
	hdoc->limiter_fds = (int *)safe_calloc(hdoc->count, sizeof(int));
	hdoc->hdoc_pids = (pid_t *)safe_calloc(hdoc->count, sizeof(int *));

	make_heredoc_lilmiter_array(exec, hdoc); // <- this is the problem!!! 
	return (1);
}