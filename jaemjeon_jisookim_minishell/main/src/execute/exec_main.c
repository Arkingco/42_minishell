/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 02:42:21 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// don't need pipe
pid_t	exec_single_cmd(t_exec *exec, pid_t ret_pid)
{
	pid_t	pid;
	
	if (exec->cmds->simple_cmd && check_built_in(exec))
		exec_go_built_in(exec);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			if (exec->cmds->redirect_input || exec->cmds->redirect_output)
				exec_handle_redirection(exec, exec->cmds, 0);
			exec_executing(exec, 0);
			exit(0);
		}
		ret_pid = ft_wait(exec->process_cnt, &pid); 
	}
	return (ret_pid);
}

// todo : make exit stat function
pid_t	exec_multi_cmd(t_exec *exec, pid_t ret_pid)
{
	t_fd	*fd;

	fd = ft_calloc(1, sizeof(t_fd));
	if (!fd)
		exit(1);
	fd->pipe_input_fd = -1;
	fd->pipe_output_fd = -1;
	fd->before_input_fd = -1;
	ret_pid = multi_process_exceve(exec, fd);
	if (ret_pid == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	free(fd);
	return (ret_pid);
}


pid_t	execute(t_cmd *cmd, t_envlst *env, char *envp[])
{
	t_exec	*exec;
	pid_t	ret_pid;
	
	// initialize
	exec = main_init_exec(exec, cmd, env, envp);
	ret_pid = 0;
	
	// heredoc
	if (exec->process_cnt == 0)
		return (0);
	else
		ret_pid = heredoc(exec, ret_pid);

	// execute
	if (exec->process_cnt == 1)
		ret_pid = exec_single_cmd(exec, ret_pid);
	else 
		ret_pid = exec_multi_cmd(exec, ret_pid);
	
	return (ret_pid);
}
