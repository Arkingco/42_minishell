/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:56:53 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 15:23:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

int	process_built_in(t_cmd *cmd, t_working_info *info, int cmd_type)
{
	int	ret;
	int	(*built_in_func)(t_cmd *cmd, t_working_info*);
	static int(*built_in_func_board[BUILT_IN_COUNT])(t_cmd*, t_working_info*)\
	= {
		[T_ECHO] = ft_echo,
		[T_CD] = ft_cd,
		[T_PWD] = ft_pwd,
		[T_EXPORT] = ft_export,
		[T_UNSET] = ft_unset,
		[T_ENV] = ft_env,
		[T_EXIT] = ft_exit
	};
	built_in_func = built_in_func_board[cmd_type];
	ret = built_in_func(cmd, info);
	g_errno = ret;
	return (ret);
}

void	process_not_built_in(t_working_info *info)
{
	pid_t	pid;
	int		exit_status;

	sigtermset(MINISHELL_HAS_CHILD);
	pid = ft_fork();
	if (pid == 0)
	{
		sigtermset(EXECUTE_CHILD);
		exec_executing(info);
	}
	else
	{
		waitpid(0, &exit_status, 0);
		sigtermset(MINISHELL_NO_CHILD);
		if (WIFEXITED(exit_status))
			g_errno = WEXITSTATUS(exit_status);
		else
			g_errno = WCOREFLAG + WTERMSIG(exit_status);
	}
}
