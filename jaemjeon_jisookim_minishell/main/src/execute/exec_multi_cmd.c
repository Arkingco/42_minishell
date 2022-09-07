/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:27:47 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if multi, execute nothing,
// but if last process(last cmd), do it!
int	exec_multi_check_built_in(t_exec *exec)
{
	char	*cmd;
	int		do_flag;

	cmd = exec->cmds->simple_cmd->string_value;
	if (!ft_strncmp(cmd, "export", ft_strlen("export")))
		ft_export(exec);
	else if(!ft_strncmp(cmd, "unset", ft_strlen("unset")))
		ft_unset(exec);
	else if (!ft_strncmp(cmd, "cd", ft_strlen("cd")))
		ft_cd(exec);
	else if (!ft_strncmp(cmd, "exit", ft_strlen("exit")))
		ft_exit(exec);
	else if (!ft_strncmp(cmd, "echo", ft_strlen("echo")))
		ft_echo(exec); 
	else if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd")))
		ft_pwd(exec);
	else if (!ft_strncmp(cmd, "env", ft_strlen("env")))
		ft_env(exec);
	return (0);
}

int	exec_multi_first(t_exec *exec)
{
	
	//pipe
	//fork -> get pid
	//dup2
	//if pid == 0 <- child process
	
	
	
	return (0);
}

int	exec_multi_last(t_exec *exec)
{
	return (0);
}

int	exec_multi_middle(t_exec *exec)
{
	exec_multi_check_built_in(exec);
	return (0);
}
