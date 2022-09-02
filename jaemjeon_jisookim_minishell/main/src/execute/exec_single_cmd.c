/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:49 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 17:08:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_single_check_built_in(t_exec *exec)
{
	char	*cmd;

	cmd = exec->cmds->simple_cmd;
	if (!ft_strncmp(cmd, "export", ft_strlen("export")))
		ft_export(SINGLE_CMD);
	else if(!ft_strncmp(cmd, "unset", ft_strlen("unset")))
		ft_unset(SINGLE_CMD);
	else if (!ft_strncmp(cmd, "cd", ft_strlen("cd")))
		ft_cd(SINGLE_CMD);
	else if (!ft_strncmp(cmd, "exit", ft_strlen("exit")))
		ft_exit(SINGLE_CMD);
	return (0);
}