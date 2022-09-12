/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 20:16:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tools_move_cmd(t_exec *exec, int i)
{
	int	j;

	j = 0;
	while (j < i) //i 만큼 cmd이동
	{
		exec->cmds = exec->cmds->next;
		j++;
	}
	return ;
}

// pipe_cnt = process_cnt -1
int	count_process(t_exec *exec)
{
	int		process;

	process = 0;
	while (exec->cmds)
	{
		process++;
		if (!exec->cmds->next)
			break ;
		exec->cmds = exec->cmds->next;
	}
	exec->cmds = exec->cmd_head; // put back cmd
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
	exec->cmd_head = cmd;
	exec->env = env;
	exec->env_head = exec->env; 
	exec->process_cnt = count_process(exec);
	get_token_count(exec);
	make_env_double_ptr(exec);
	make_path_list(exec);
	return (exec);
}
