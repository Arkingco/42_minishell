/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 17:08:16 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_multi_check_built_in(t_exec *exec)
{
	char	*cmd;

	cmd = exec->cmds->simple_cmd;
	if (!ft_strncmp(cmd, "export", ft_strlen("export")))
		ft_export(MULTI_CMD);
	else if(!ft_strncmp(cmd, "unset", ft_strlen("unset")))
		ft_unset(MULTI_CMD);
	else if (!ft_strncmp(cmd, "cd", ft_strlen("cd")))
		ft_cd(MULTI_CMD);
	else if (!ft_strncmp(cmd, "exit", ft_strlen("exit")))
		ft_exit(MULTI_CMD);
	else if (!ft_strncmp(cmd, "echo", ft_strlen("echo")))
		ft_echo(MULTI_CMD);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd")))
		ft_pwd(MULTI_CMD);
	else if (!ft_strncmp(cmd, "env", ft_strlen("env")))
		ft_env(MULTI_CMD);
	return (0);
}

int	exec_multi_first(t_exec *exec, t_cmd *cmd)
{
	
	return (0);
}

int	exec_multi_last(t_exec *exec, t_cmd *cmd)
{
	return (0);
}

int	exec_multi_middle(t_exec *exec, t_cmd *cmd)
{
	return (0);
}