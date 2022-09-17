/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:52:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 12:03:50 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_exec_struct_final_cmd_loop(t_exec *exec, t_cmd *cmd, int i)
{
	char *cmd_str;

	cmd_str = 0;
	if (cmd->simple_cmd && cmd->simple_cmd->string_value)
		cmd_str = ft_strdup(cmd->simple_cmd->string_value);
	if (!cmd_str)
	{
		free(cmd_str);
		return ;
	}
	exec->final_cmd_str[i] = ft_strdup(cmd_str); 
	free(cmd_str);
	return ;
}

void	set_exec_struct_final_cmd_str(t_exec *exec, int index)
{
	t_cmd	*cmd;
	int		i;

	exec->final_cmd_str = ft_calloc(exec->token_cnt[index] + 1, sizeof(char *));
	if (!exec->final_cmd_str)
		return ;
		
	cmd = get_cmd_for_index(exec, index);
	i = 0;
	while (cmd->simple_cmd && cmd->simple_cmd->string_value)
	{
		set_exec_struct_final_cmd_loop(exec, cmd, i);
		cmd->simple_cmd = cmd->simple_cmd->next;
		i++;
	}
	return ;
}


void	set_final_path_str(t_exec *exec)
{
	char			*slash_cmd;
	char			*temp;
	struct stat		buf;
	int				i;

	if (!exec->final_cmd_str[0])
		return ;
	if (ft_strchr(exec->final_cmd_str[0], '/') != NULL) // Absolute path case(절대경로)
	{
		exec->final_path = exec->final_cmd_str[0];
		ft_exit_if(exec, !(exec->final_path));
		return ;
	}
	slash_cmd = ft_strjoin("/", exec->final_cmd_str[0]);
	ft_exit_if(exec, !(slash_cmd));
	i = 0;
	while (exec->path_lst[i])
	{
		temp = ft_strjoin(exec->path_lst[i], slash_cmd);
		ft_exit_if(exec, !(temp));
		if (!stat(temp, &buf))
		{
			exec->final_path = temp;
			break ;
		}
		free(temp);
		i++;
	}
	free(slash_cmd);
	return ;
}


int	init_exec_struct(t_exec *exec, int process_number)
{
	set_exec_struct_final_cmd_str(exec, process_number);
	if (!exec->cmds)
		return (0);
	set_final_path_str(exec);

	return (0);
}
