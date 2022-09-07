/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:55:19 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// don't need pipe
int	exec_single_cmd(t_exec *exec)
{
	int		process_number;
	int		is_built_in;
	int		stat;
	pid_t	pid;
	
	process_number = 0;
	if (check_built_in(exec))
		exec_go_built_in(exec);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			init_exec_struct(exec, process_number);
			if (exec->final_path == NULL)
				exec->final_path = exec->cmds->simple_cmd->string_value;
			stat = execve(exec->final_path, exec->final_cmd_str, exec->env_lst); //정상적으로 끝나면 여기서 종료.
			if (stat == -1)
			{
				ft_putstr_fd("ERROR : execve() function error. \n", 2);
				exit(1);
			}
			exit(127);
		}
		ft_wait(&stat); // todo : return exit stat
	}
	return (0);
}

// todo : make exit stat function

int	exec_multi_cmd(t_exec *exec)
{
	int		process_number;
	int		is_built_in;
	int		stat;
	pid_t	pid;
	
	process_number = 0;
	if (check_built_in(exec))
		exec_go_built_in(exec);
	else
	{
		exec_main_forking_process(exec);
		
		// if (pid == 0)
		// {
		// 	init_exec_struct(exec, process_number);
		// 	if (exec->final_path == NULL)
		// 		exec->final_path = exec->cmds->simple_cmd->string_value;
		// 	stat = execve(exec->final_path, exec->final_cmd_str, exec->env_lst); //정상적으로 끝나면 여기서 종료.
		// 	if (stat == -1)
		// 	{
		// 		ft_putstr_fd("ERROR : execve() function error. \n", 2);
		// 		exit(1);
		// 	}
		// 	exit(127);
		// }
		// ft_wait(&stat); // todo : return exit stat

		
	}

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





int	execute(t_cmd *cmd, t_envlst *env, char *envp[])
{
	t_exec	*exec;
	
	
	exec = main_init_exec(exec, cmd, env, envp);

	if (exec->process_cnt == 0)
		return (0);
	else if (exec->process_cnt == 1)
		exec_single_cmd(exec);
	else 
		exec_multi_cmd(exec);

	// printf("\n\n---------------\n");
	// printf("exec->process count : %d\n", exec->process_cnt);
	// printf("exec->final_path : %d\n", exec->process_cnt);
	// int i = 0;
	// while (exec->env_lst[i])
	// {
	// 	printf("[%d] : %s\n", i, exec->env_lst[i]);
	// 	i++;
	// }

	
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
