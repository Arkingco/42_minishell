/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/09 15:07:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


// don't need pipe
int	exec_single_cmd(t_exec *exec)
{
	int		stat;
	pid_t	pid;
	
	if (check_built_in(exec))
		exec_go_built_in(exec);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			exec_executing(exec, 0, stat);
		}
		ft_wait(&stat, 0); // todo : return exit stat
	}
	return (0);
}

// todo : make exit stat function
int	exec_multi_cmd(t_exec *exec)
{
	pid_t	ret_pid;

	ret_pid = multi_process_exceve(exec);
	if (ret_pid == -1)
		ft_putstr_fd("ERROR! : error during getting ret_pid.\n", 2);

	return (ret_pid); // returning pid, pid fail(-1)
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
	return (0);
}


	// printf("\n\n========= DEBUG PIPE ============\n");
	// printf("pipe[0] : %d\n", exec->pipe_fd[0]);
	// printf("pipe[0] : %d\n", exec->pipe_fd[1]);
	// printf("pipe[0] : %d\n", exec->pipe_fd[2]);
	// printf("\n========= DEBUG PIPE ============\n\n");

	// ft_close(exec->pipe_fd[0]);
	// ft_close(exec->pipe_fd[1]);
	// ft_close(exec->pipe_fd[2]);

	// // debug
	// dprintf(2, "\n=============[%d] DEBUG ============\n", process_number);
	// int idx = 0;
	// dprintf(2, "exec->final_path : %s\n", exec->final_path);
	// dprintf(2, "exec->token_cnt[process_number]: %d\n", exec->token_cnt[process_number]);
	
	// while (idx < exec->token_cnt[process_number]) 
	// {
	// 	dprintf(2, "exec->final_cmd_str[%d] : %s\n", idx, exec->final_cmd_str[idx]);
	// 	idx++;
	// }
	// dprintf(2, "exec->final_cmd_str[%d] : %s (last)\n", idx, exec->final_cmd_str[idx]); // needs to have (null);
	// dprintf(2, "============= DEBUG ============\n");
	// dprintf(2, "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	// // debug
