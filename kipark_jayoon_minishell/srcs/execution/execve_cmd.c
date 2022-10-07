/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:49:03 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 10:49:53 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "execution.h"
#include "libft.h"

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

void	execve_cmd(t_args_execve *p_args, char **envp)
{
	if (p_args->path)
		execve_include_path(p_args, envp);
	else
		execve_include_slash_or_no_path(p_args, envp);
}
