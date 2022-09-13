/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 17:13:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_token_count(t_exec *exec)
{
	int	i;

	i = 0;
	exec->token_cnt = ft_calloc(1, sizeof(int *) * exec->process_cnt);
	if (!exec->token_cnt)
	{
		ft_putstr_fd("ERROR : calloc() function error. \n", 2);
		free(exec->token_cnt);
		exit(1);
	}
	while (i < exec->process_cnt)
	{
		exec->token_cnt[i] = get_simple_cmd_count(exec, i);
		i++;
	}
	return ;
}


int	get_simple_cmd_count(t_exec *exec, int i)
{
	int		cmd_count;
	t_cmd	*cmd;
	t_token	*token;
	
	cmd = get_cmd_for_index(exec, i);
	token = cmd->simple_cmd;
	cmd_count = 0;
	while (token) //get token length
	{
		token = token->next;
		cmd_count++;
	}
	return (cmd_count);
}
