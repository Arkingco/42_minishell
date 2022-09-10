/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/11 05:04:01 by jaemjeon         ###   ########.fr       */
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

int	is_already_exec_path(char *cmd_string)
{
	if (ft_strlen(cmd_string) < 2)
		return (FALSE);
	if (ft_strncmp("./", cmd_string, 2) == 0 || \
		ft_strncmp("~/", cmd_string, 2) == 0)
		return (TRUE);
}

void	expand_homepath(char **cmd_string, t_envlst *env)
{
	char	*new_cmd_string;
	char	*homepath;

	homepath = ft_getenv(env, "HOME");
	if (homepath == NULL)
		return ;
	if (**cmd_string == '~')
	{
		new_cmd_string = ft_strjoin(homepath, *cmd_string + 1);
		free(*cmd_string);
		*cmd_string = new_cmd_string;
	}
}

int	expand_homepath_and_check_is_there(t_cmd *cmd, t_envlst *env)
{
	struct stat	file_stat;

	expand_homepath(&cmd->simple_cmd->string_value, env);
	if (stat(cmd->simple_cmd->string_value, &file_stat) == 0)
		return (TRUE);
	return (FALSE);
}

int	set_absolute_path(t_cmd *cmd, t_envlst *env)
{
	const char	**path_board = get_path_board(env);
	int		index;
	char	*exec_path;
	struct stat	file_stat;

	if (path_board == NULL)
		return (FALSE);
	index = 0;
	while (path_board[index] != NULL)
	{
		exec_path = ft_strjoin_triple(path_board[index], "/",
									  cmd->simple_cmd->string_value);
		if (stat(exec_path, &file_stat) == 0)
		{
			free(cmd->simple_cmd->string_value);
			cmd->simple_cmd->string_value = exec_path;
			return (TRUE);
		}
		free(exec_path);
		index++;
	}
	return (FALSE);
}

int	set_exec_path(t_cmd *cmd, t_envlst *env)
{
	char		*execv_path;
	char		*cmd_string;

	cmd_string = cmd->simple_cmd->string_value;
	if (is_already_exec_path(cmd_string) == TRUE)
	{
		expand_homepath(&cmd_string, env);
		return (is_valid_cmd_path(cmd_string));
	}
	else
	{
		return (set_absolute_path(&cmd_string, env));
	}
}

void	process_not_built_in(t_cmd *cmd, t_envlst *env)
{
	pid_t	pid;

	if (set_exec_path(cmd, env) == FALSE)
	{

	}
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
