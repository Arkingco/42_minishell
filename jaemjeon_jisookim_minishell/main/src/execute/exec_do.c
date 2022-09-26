/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:54:01 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 22:13:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

static void	exec_exit(t_working_info *info)
{
	if (errno == 13)
	{
		process_errno(errno, info->cmd->simple_cmd->string_value, \
			PERMMISION_DENIED_ERR);
		exit(126);
	}
	if (errno == 2)
	{
		process_errno(errno, info->cmd->simple_cmd->string_value, \
			CMD_NOT_FOUND_ERR);
		exit(127);
	}
	exit(1);
}

void	exec_remove_empty(t_cmd **cmd)
{
	t_token *prev;

	while (ft_strlen((*(cmd))->simple_cmd->string_value) == 0)
	{
		prev = (*(cmd))->simple_cmd;
		(*(cmd))->simple_cmd = (*(cmd))->simple_cmd->next;
		(*(cmd))->simple_cmd->prev = NULL;
		free(prev->string_value);
		free(prev);
	}
}

void	exec_executing(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;

	// exec_remove_empty(&(info->cmd));
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
		exec_exit(info);
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
