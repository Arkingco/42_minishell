/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 20:29:25 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_cmd_type(t_cmd *cmd)
{
	char				*cmd_string;
	int					index;
	static char *const	built_in_board[] = \
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

char	**get_exec_argv(t_cmd *cmd)
{
	t_token	*cmd_lst;
	char	**exec_argv;
	int		index;

	index = 0;
	cmd_lst = cmd->simple_cmd;
	exec_argv = \
			(char **)ft_calloc(ft_token_lstsize(cmd_lst) + 1, sizeof(char *));
	if (exec_argv == NULL)
	{
		exec_argv = 0;
		return (NULL);
	}
	while (cmd_lst != NULL)
	{
		exec_argv[index] = cmd_lst->string_value;
		index++;
		cmd_lst = cmd_lst->next;
	}
	return (exec_argv);
}

void	close_useless_fds(int *fd)
{
	if (fd[0] != -1)
		ft_close(fd[0]);
	if (fd[1] != -1)
		ft_close(fd[1]);
	if (fd[2] != -1)
		ft_close(fd[2]);
}
