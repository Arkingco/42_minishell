/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 00:54:01 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"
#include "../../include/built_in.h"

int	get_cmd_type(t_cmd *cmd)
{
	char				*cmd_string;
	int					index;
	static const char	*built_in_board[] = \
	{
	[T_ECHO] = "echo",
	[T_CD] = "cd",
	[T_PWD] = "pwd",
	[T_EXPORT] = "export",
	[T_UNSET] = "unset",
	[T_ENV] = "env",
	[T_EXIT] = "exit"
	};

	cmd_string = cmd->simple_cmd->string_value;
	index = 0;
	while (index < BUILT_IN_COUNT)
	{
		if (ft_strncmp(cmd_string, built_in_board[index], -1) == 0)
			return (index);
		index++;
	}
	return (index);
}

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

char	**get_exec_argv(t_cmd *cmd)
{
	t_token *cmd_lst;
	char	**exec_argv;
	int		index;

	index = 0;
	cmd_lst = cmd->simple_cmd;
	exec_argv = \
			(char **)ft_calloc(ft_token_lstsize(cmd_lst) + 1, sizeof(char *));
	if (exec_argv == NULL)
		return (NULL);
	while (cmd_lst != NULL)
	{
		exec_argv[index] = cmd_lst->string_value;
		index++;
		cmd_lst = cmd_lst->next;
	}
	return (exec_argv);
}