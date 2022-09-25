/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:54:01 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:37:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	exec_executing(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;

	set_exec_path(info->cmd, info);
	exec_argv = get_exec_argv(info->cmd);
	exec_env = ft_envlst_to_envp(info->env);
	if (exec_argv == NULL || exec_env == NULL)
	{
		process_errno(errno, "malloc_failed", MALLOC_FAILED_ERR);
		exit(g_errno);
	}
	if (execve(info->cmd->simple_cmd->string_value, exec_argv, exec_env) \
		== FAIL)
	{
		process_errno(errno, info->cmd->simple_cmd->string_value, \
			CMD_NOT_FOUND_ERR);
		exit(g_errno);
	}
}

int	ft_wait_childs(pid_t *child_pids, int cmd_count)
{
	int	index;
	int	exit_status;

	index = 0;
	while (index < cmd_count)
	{
		waitpid(child_pids[index], &exit_status, 0);
		index++;
	}
	return (exit_status);
}
