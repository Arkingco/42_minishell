/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/10 21:14:18 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_built_in(t_cmd *cmd, int cmd_type, t_envlst *env)
{
	void	(*built_in_func)(t_cmd, t_envlst);
	static const void (*built_in_func_board[BUILT_IN_COUNT])(t_cmd, t_envlst) =
	{
		[T_ECHO] = ft_echo,
		[T_CD] = ft_cd,
		[T_PWD] = ft_pwd,
		[T_EXPORT] = ft_export,
		[T_UNSET] = ft_unset,
		[T_ENV] = ft_env,
		[T_EXIT] = ft_exit
	};

	built_in_func_board[cmd_type];
}

int	set_absolute_path(t_cmd *cmd, t_envlst *env)
{
	char		**path_board;
	char		*execv_path;
	char		*cmd_string;
	struct stat	file_stat;
	int			index;

	cmd_string = cmd->simple_cmd->string_value;
	if (stat(cmd_string, &file_stat) == 0)
		return (TRUE);
	path_board = get_path_board(env);
	if (path_board != NULL)
	{
		index = 0;
		while (path_board[index] != NULL)
		{
			execv_path = ft_strjoin_triple(path_board[index], "/", cmd_string);
			index++;
		}
	}
}

void	process_not_built_in(t_cmd *cmd, t_envlst *env)
{
	pid_t	pid;

	set_absolute_path(cmd, env);
	pid = fork();
	if (pid == 0)
	{
		
	}
}

void	process_single_cmd(t_cmd *cmd, t_envlst *env)
{
	int	cmd_type;

	cmd_type = get_cmd_type(cmd);
	if (cmd_type == NOT_BUILT_IN)
		process_not_built_in(cmd, env);
	else
		process_built_in(cmd, cmd_type, env);
}

void	process_multi_cmd(t_cmd *cmd, t_envlst *env)
{
	while ()
}

void	execute(t_cmd *cmd, t_envlst *env)
{
	int	cmd_count;

	cmd_count = ft_cmdlst_size(cmd);
	if (cmd_count == 0)
		return ;
	else if (cmd_count == 1)
		process_single_cmd(cmd, env);
	else
		process_multi_cmd(cmd, env);
}
