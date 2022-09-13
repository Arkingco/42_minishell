/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 14:07:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// don't need pipe
int	exec_single_cmd(t_exec *exec)
{
	int		stat;
	pid_t	pid;
	pid_t	ret_pid;
	
	ret_pid = 0;
	if (exec->cmds->simple_cmd && check_built_in(exec))
		exec_go_built_in(exec);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			if (exec->cmds->redirect_input || exec->cmds->redirect_output)
				exec_handle_redirection(exec, 0);
			exec_executing(exec, 0, stat);
			exit(0);
		}
		ret_pid = ft_wait(exec, &pid); // todo : return exit stat
	}
	return (ret_pid);
}

// todo : make exit stat function
int	exec_multi_cmd(t_exec *exec)
{
	pid_t	ret_pid;
	t_fd	*fd;

	fd = ft_calloc(1, sizeof(t_fd));
	if (!fd)
		exit(1);
	fd->input_fd = -1;
	fd->output_fd = -1;
	fd->before_input_fd = -1;
	ret_pid = multi_process_exceve(exec, fd);
	if (ret_pid == -1)
		ft_putstr_fd("ERROR! : error during getting ret_pid.\n", 2);
	free(fd);
	return (ret_pid); // returning pid, pid fail(-1)
}


int	execute(t_cmd *cmd, t_envlst *env, char *envp[])
{
	t_exec	*exec;
	pid_t	ret_pid;
	
	exec = main_init_exec(exec, cmd, env, envp);
	if (exec->process_cnt == 0)
		return (0);
	else if (exec->process_cnt == 1)
		ret_pid = exec_single_cmd(exec);
	else 
		ret_pid = exec_multi_cmd(exec);
	//printf("\n\nreturn pid is : %d\n\n", ret_pid);
	return (ret_pid);
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
