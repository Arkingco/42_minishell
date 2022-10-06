/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 18:07:24 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "execution.h"
#include "exit_status.h"
#include <fcntl.h>
#include "libft.h"
#include "parser.h"

static void	execve_include_path(t_args_execve *p_args, char **envp)
{
	char	*file_path;
	int		i;
	int		is_permission_denied;

	i = -1;
	is_permission_denied = 0;
	while (p_args->path[++i])
	{
		file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
		execve(file_path, p_args->argv, envp);
		if (errno == EACCES)
			is_permission_denied = 1;
		ft_safe_free(file_path);
	}
	if (is_permission_denied)
	{
		ft_multi_putendl_fd("minishell: ", p_args->argv[0],
			": Permission denied", 2);
		exit(126);
	}
	ft_multi_putendl_fd("minishell: ", p_args->argv[0], \
		": command not found", 2);
	exit(127);
}

static void	execve_include_slash_or_no_path(t_args_execve *p_args, char **envp)
{
	execve(p_args->argv[0], p_args->argv, envp);
	if (errno == EACCES)
	{
		ft_multi_putendl_fd("minishell: ", p_args->argv[0],
			": Permission denied", 2);
		exit(126);
	}
	ft_multi_putendl_fd("minishell: ", p_args->argv[0], \
		": No such file or directory", 2);
	exit(127);
}

static void	execve_cmd(t_args_execve *p_args, char **envp)
{
	if (p_args->path)
		execve_include_path(p_args, envp);
	else
		execve_include_slash_or_no_path(p_args, envp);
}

void	do_it_child(t_parsing_list *l_parsing, t_info_cmd *info_cmd, int *fd)
{
	if (l_parsing->redir_iter)
		init_fd_by_redirection(l_parsing->redir_iter, fd, info_cmd->l_here_doc);
	if (fd[0] != 0 && !is_last_cmd(info_cmd))
		safe_close(fd[0]);
	if (fd[1] != 1)
	{
		safe_dup2(fd[1], 1);
		safe_close(fd[1]);
	}
	if (fd[2] != 0)
	{
		safe_dup2(fd[2], 0);
		safe_close(fd[2]);
	}
	if (l_parsing->l_simple_cmd)
	{
		init_execve_args(l_parsing, &info_cmd->args_execve,
			info_cmd->args_execve.envp);
		execve_cmd(&info_cmd->args_execve, info_cmd->args_execve.envp);
	}
	exit(0);
}
