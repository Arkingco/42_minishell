/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 13:27:01 by jaemjeon         ###   ########.fr       */
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
			set_sigtermset(IN_CHILD);
			if (exec->cmds->redirect_input || exec->cmds->redirect_output)
				exec_handle_redirection(exec, exec->cmds, 0);
			exec_executing(exec, 0);
			exit(0);
		}
		set_sigtermset(IN_MINISHELL_HAS_CHILD);
		ret_pid = ft_wait(exec->process_cnt, &pid); 
		set_sigtermset(IN_MINISHELL_NO_CHILD);
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


pid_t	execute(t_info *info, t_envlst *env)
{
	pid_t	ret_pid;
	
	// initialize
	main_init_exec(info, env);
	ret_pid = 0;
	
	// heredoc
	if (info->exec->process_cnt == 0)
		return (0);
	else
		ret_pid = heredoc(exec, ret_pid);
	if (ret_pid == FALSE)
		return (FALSE);
	// execute
	if (exec->process_cnt == 1)
		ret_pid = exec_single_cmd(exec, ret_pid);
	else 
		ret_pid = exec_multi_cmd(exec, ret_pid);
	
	return (ret_pid);
}
