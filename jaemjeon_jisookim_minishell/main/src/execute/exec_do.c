/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:54:01 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 11:01:37 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	single_cmd_child_process(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;
	struct stat	stat_info;
	int			errno_tmp;

	exec_argv = get_exec_argv(info->cmd);
	exec_env = ft_envlst_to_envp(info->env);
	if (exec_argv == NULL || exec_env == NULL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	if (execve(info->cmd->simple_cmd->string_value, exec_argv, exec_env) \
		== FAIL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	exit(errno);
}

void	exec_executing(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;
	int			errno_tmp;
	struct stat	stat_info;

	if (set_exec_path(info->cmd, info) == FALSE)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	exec_argv = get_exec_argv(info->cmd);
	exec_env = ft_envlst_to_envp(info->env);
	if (exec_argv == NULL || exec_env == NULL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	if (execve(info->cmd->simple_cmd->string_value, exec_argv, exec_env) \
		== FAIL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
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
