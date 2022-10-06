/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:01:37 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <fcntl.h>
#include "libft.h"
#include "parser.h"

static void	execve_cmd(t_args_execve *p_args, char **envp)
{
	size_t	i;
	char	*file_path;

	i = 0;
	if (p_args->path)
	{
		while (p_args->path[i])
		{
			file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
			execve(file_path, p_args->argv, envp);
			ft_safe_free(file_path);
			i++;
		}
		ft_multi_putendl_fd("minishell: ", p_args->argv[0],
			": command not found", 2);
	}
	else
	{
		execve(p_args->argv[0], p_args->argv, envp);
		ft_multi_putendl_fd("minishell: ", p_args->argv[0],
			": No such file or directory", 2);
	}
	ft_safe_free_two_dimentions_arr(p_args->path);
	ft_safe_free_two_dimentions_arr(p_args->argv);
	exit(127);
}

void	do_it_child(t_parsing_list *l_parsing, t_info_cmd *info_cmd, int *fd)
{
	if (l_parsing->redir_iter)
		init_fd_by_redirection(l_parsing->redir_iter, fd, info_cmd->l_here_doc);
	if (fd[0] != 0 && info_cmd->idx_curr_proc != info_cmd->num_proc - 1)
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
