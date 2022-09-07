/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_built_in.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:33:15 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:33:50 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_built_in(t_exec *exec)
{
	char	*cmd;

	cmd = exec->cmds->simple_cmd->string_value;
	if (!ft_strncmp(cmd, "export", ft_strlen("export") + 1))
		return (1);
	else if(!ft_strncmp(cmd, "unset", ft_strlen("unset") + 1))
		return (1);
	else if (!ft_strncmp(cmd, "cd", ft_strlen("cd") + 1)) 
		return (1);
	else if (!ft_strncmp(cmd, "exit", ft_strlen("exit") + 1))
		return (1);
	else if (!ft_strncmp(cmd, "echo", ft_strlen("echo") + 1))
		return (1);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd") + 1))
		return (1);
	else if (!ft_strncmp(cmd, "env", ft_strlen("env") + 1))
		return (1);
	return (0);
}

void	exec_single_check_built_in(t_exec *exec)
{
	char	*cmd;

	cmd = exec->cmds->simple_cmd->string_value;
	if (!ft_strncmp(cmd, "export", ft_strlen("export") + 1))
		ft_export(exec);
	else if(!ft_strncmp(cmd, "unset", ft_strlen("unset") + 1))
		ft_unset(exec);
	else if (!ft_strncmp(cmd, "cd", ft_strlen("cd") + 1)) 
		ft_cd(exec);
	else if (!ft_strncmp(cmd, "exit", ft_strlen("exit") + 1))
		ft_exit(exec);
	else if (!ft_strncmp(cmd, "echo", ft_strlen("echo") + 1))
		ft_echo(exec); // if multi, execute nothing
	else if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd") + 1))
		ft_pwd(exec);
	else if (!ft_strncmp(cmd, "env", ft_strlen("env") + 1))
		ft_env(exec);
	return ;
}


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
