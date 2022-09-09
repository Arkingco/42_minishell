/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:52:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/09 14:56:18 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_exec_struct_final_cmd_loop(t_exec *exec, char *cmd_str, int i)
{
	cmd_str = ft_strdup(exec->cmds->simple_cmd->string_value);
	exec->final_cmd_str[i] = ft_strdup(cmd_str); 
	free(cmd_str);
	return ;
}

void	set_exec_process_number_init(t_exec *exec, char *cmd_str, int j)
{
	int	i;
	int	process_number;

	i = 0;
	process_number = j;
	exec->cmds = exec->cmd_head;
	while (i < process_number)
	{
		exec->cmds = exec->cmds->next;
		i++;
	}
	return ;
}

void	set_exec_struct_final_cmd_str(t_exec *exec, int j) // j == process number
{
	int		i;
	char	*cmd_str;

	exec->final_cmd_str = ft_calloc(1, sizeof(char *) * (exec->token_cnt[j] + 1));
	exec->final_cmd_str[exec->token_cnt[j]] = NULL;
	if (!exec->final_cmd_str)
		ft_exit(exec);
	
	set_exec_process_number_init(exec, cmd_str, j);
	i = 0;
	while (exec->cmds->simple_cmd->string_value)
	{
		set_exec_struct_final_cmd_loop(exec, cmd_str, i);
		if (exec->cmds->simple_cmd->next)
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
		else
			break;
		i++;
	}
	set_exec_struct_final_cmd_loop(exec, cmd_str, i);
	exec->cmds = exec->cmd_head; // init
	return ;
}


char	*set_final_path_str(t_exec *exec)
{
	char			*slash_cmd;
	char			*temp;
	struct stat		buf;
	int				i;

	slash_cmd = ft_strjoin("/", exec->final_cmd_str[0]);
	if (!(slash_cmd))
		ft_exit(exec);
	i = 0;
	while (exec->path_lst[i])
	{
		temp = (char *)ft_calloc(1, ft_strlen(exec->path_lst[i]) \
									+ ft_strlen(slash_cmd) + 1);
		temp = ft_strjoin(exec->path_lst[i], slash_cmd);
		if (!temp)
			ft_exit(exec);
		if (!stat(temp, &buf))
		{
			exec->final_path = temp;
			return (exec->final_path);
		}
		free(temp);
		i++;
	}
	free(slash_cmd);
	return (NULL);
}


int	init_exec_struct(t_exec *exec, int process_number)
{
	set_exec_struct_final_cmd_str(exec, process_number);
	exec->final_path = set_final_path_str(exec);

	return (0);
}
