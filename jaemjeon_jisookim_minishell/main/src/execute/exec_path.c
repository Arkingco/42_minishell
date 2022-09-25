/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:43:12 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 18:32:48 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_path_board(t_envlst *env)
{
	char	*path_line;
	char	**path_board;

	path_line = ft_getenv(env, "PATH");
	if (path_line == NULL)
		return (NULL);
	path_board = ft_split(path_line, ':');
	if (path_board == NULL)
		ft_error_exit(1, "malloc error in ft_split");
	return (path_board);
}

int	is_already_exec_path(char *cmd_string)
{
	if (ft_strchr(cmd_string, '/') != NULL)
		return (TRUE);
	else
		return (FALSE);
}

int	is_valid_cmd_path(char *cmd_string)
{
	struct stat	file_stat;

	if (stat(cmd_string, &file_stat) == 0)
		return (TRUE);
	return (FALSE);
}

int	set_absolute_path(t_cmd *cmd, t_working_info *info)
{
	const char	**path_board = (const char **)get_path_board(info->env);
	int			index;
	char		*exec_path;
	struct stat	file_stat;

	if (path_board == NULL)
		return (FALSE);
	index = 0;
	while (path_board[index] != NULL)
	{
		exec_path = ft_strjoin_triple((char *)path_board[index], "/",
									cmd->simple_cmd->string_value);
		if (stat(exec_path, &file_stat) == 0)
		{
			free(cmd->simple_cmd->string_value);
			cmd->simple_cmd->string_value = exec_path;
			return (TRUE);
		}
		free(exec_path);
		exec_path = 0;
		index++;
	}
	return (FALSE);
}

int	set_exec_path(t_cmd *cmd, t_working_info *info)
{
	char	*cmd_string;

	cmd_string = cmd->simple_cmd->string_value;
	if (is_already_exec_path(cmd_string) == TRUE)
		return (is_valid_cmd_path(cmd_string));
	else
		return (set_absolute_path(cmd, info));
}
