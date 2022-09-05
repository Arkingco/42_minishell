/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 14:03:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// don't need pipe
int	exec_single_cmd(t_exec *exec, t_envlst *env)
{
	int		is_built_in;
	int		stat;
	pid_t	pid;
	
	exec_single_check_built_in(exec);
	pid = ft_fork();
	if (pid == 0)
	{
		ft_exceve(exec->final_path, exec->execve_cmds, exec->env_lst);
	}
	//execute in child process
	//wait_pid in parent process
	//wait_pid control
	
	return (ft_wait(&stat));
}

int	exec_multi_cmd(t_exec *exec, t_envlst *env, int *wait_ret)
{
	(void)exec;
	(void)env;
	(void)wait_ret;
	// int	i;
	// int	pid;
	
	// i = 0;
	// pid = exec_fork_process(exec); // make child process
	// exec_pipe_control(exec); // make and dup2 pipes
	// while (exec->cmds)
	// {
	// 	if (i == 0) // 처음
	// 	{
	// 		exec_multi_first(exec);
	// 	}
	// 	else if (i == exec->process_cnt - 1) // 마지막
	// 	{
	// 		exec_multi_last(exec); // built in needs to work
	// 	}
	// 	else // 중간
	// 	{
	// 		exec_multi_middle(exec);
	// 	}
	// 	exec->cmds = exec->cmds->next;
	// 	if (!exec->cmds)
	// 		break ;
	// }
	// wait_ret = ft_wait(&stat);
	
	return (0);
}

int	execute(t_cmd *cmd, t_envlst *env)
{
	t_exec	*exec;
	int		wait_ret;

	printf("hihi\n");
	exec = main_init_exec(exec, cmd, env); //0904 finished
	printf("\n\n---------------\n");
	printf("exec->process count : %d\n", exec->process_cnt);
	printf("exec->final_path : %d\n", exec->process_cnt);
	int i = 0;
	while (exec->env_lst[i])
	{
		printf("[%d] : %s\n", i, exec->env_lst[i]);
		i++;
	}

	
	// if (cmd && !cmd->next)
	// {	
	// 	wait_ret = exec_single_cmd(exec, env);
	// }
	// else
	// {
	// 	wait_ret = exec_multi_cmd(exec, env, &wait_ret);
	// }
	return (0);
}