/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 14:05:43 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (process == sizeof(int))
		{
			ft_putstr_fd("ERROR : process size too big. ", 2);
			exit(BAD_EXIT);
		}
		exec->cmds = exec->cmds->next;
	}
	exec->cmds = exec->cmd_head; // put back cmd
	return (process);
}

// all of the cmd string
// main cmd
// execve(const char *path, char *const argv[], char *const envp[]);
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env)
{
	exec = ft_calloc(1, sizeof(t_exec));
	if (!exec)
	{
		ft_putstr_fd("ERROR : calloc() function error. ", 2);
		free(exec);
		exit(BAD_EXIT);
	}
	exec->cmds = cmd;
	exec->cmd_head = cmd;
	exec->process_cnt = count_process(exec);
	exec->env = env;

	// printf("/n/n/n == DEBUG ++ \n\n\n");
	// while (exec->env->key && exec->env->next)
	// {
	// 	printf("%s : %s \n", exec->env->key, exec->env->value);
	// 	exec->env = exec->env->next;
	// }
	make_env_double_ptr(exec);
	exec->execve_cmds = get_execve_cmds(exec);
	//main_get_final_paths(exec); // seg fault
	//printf("g\n");
	
	exit(0);

	return (exec);
}
