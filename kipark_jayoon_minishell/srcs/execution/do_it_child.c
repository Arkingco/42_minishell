/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/02 14:28:56 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libft.h"
#include "parser.h"

//
#include <stdio.h>

static void	execve_cmd(t_args_execve *p_args, char **envp)
{
	size_t	i;
	char	*file_path;

	i = 0;
	while (p_args->path[i])
	{
		file_path = ft_safe_strjoin(p_args->path[i], p_args->argv[0]);
		execve(file_path, p_args->argv, envp);
		ft_safe_free(file_path);
		i++;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(p_args->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_safe_free_two_dimentions_arr(p_args->path);
	ft_safe_free_two_dimentions_arr(p_args->argv);
	exit(127);
}

void	do_it_child(t_parsing_list *l_parsing, t_args_execve *p_args_execve,
			int *fd, t_info_process *info_proc)
{
	// int	redir_fd[2];

	init_execve_args(l_parsing, p_args_execve, p_args_execve->envp);
	// redirection 으로 update fd
	
	if (info_proc->idx_curr_proc != 0)
	{
		safe_dup2(fd[2], 0);
		safe_close(fd[2]);
	}
	if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
	{
		safe_close(fd[0]);
		safe_dup2(fd[1], 1);
		safe_close(fd[1]);
	}
	execve_cmd(p_args_execve, p_args_execve->envp);
}
