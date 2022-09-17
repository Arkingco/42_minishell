/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 12:38:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*get_cmd_for_index(t_exec *exec, int index)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = exec->cmds;
	while (i < index) //i 만큼 cmd이동
	{
		cmd = cmd->next;
		i++;
	}
	return (cmd);
}

// pipe_cnt = process_cnt -1
int	count_process(t_exec *exec)
{
	int		process;
	t_cmd	*cmd;

	process = 0;
	cmd = get_cmd_for_index(exec, 0);
	while (cmd)
	{
		process++;
		if (!cmd->next)
			break ;
		cmd = cmd->next;
	}
	return (process);
}

void	make_path_list(t_exec *exec)
{
	int		i;

	i = 0;
	while (i < exec->count_key)
	{
		if (ft_strnstr(exec->env_lst[i], "PATH=", 5)) //find PATH in env
		{
			exec->path_lst = ft_split((exec->env_lst[i] + 5), ':'); //store path in exec->path_lst
			if (!exec->path_lst)
			{
				ft_putstr_fd("ERROR : error while making list.\n", 2);
				free(exec->path_lst);
				exit(127);
			}
		}
		i++;
	}
	return ;
}

t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env, char **envp)
{
	exec = ft_calloc(1, sizeof(t_exec));
	if (!exec)
	{
		ft_putstr_fd("ERROR : calloc() function error. ", 2);
		free(exec);
		exit(1);
	}
	exec->cmds = cmd;
	exec->env = env;
	exec->env_head = exec->env; 
	exec->process_cnt = count_process(exec);
	get_token_count(exec);
	make_env_double_ptr(exec);
	make_path_list(exec);
	return (exec);
}
