/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 12:14:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_token_count(t_exec *exec)
{
	int	i;
	t_cmd	*cmd;

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
		cmd = get_cmd_for_index(exec, i);
		exec->token_cnt[i] = fill_token_count_array(cmd);
		i++;
	}
	return ;
}


int	fill_token_count_array(t_cmd *cmd)
{
	t_token	*token;
	int		token_count;
	
	token = 0;
	if (!cmd->simple_cmd)
		return (0);
	token = cmd->simple_cmd;
	while (token)
	{
		token = token->next;
		token_count++;
	}
	return (token_count);
}
