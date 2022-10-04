/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 17:57:40 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <fcntl.h>
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

// static void	init_input_fd(t_redir_chunk *l_input, int *fd)
// {
// 	while (l_input)
// 	{
// 		if (l_input->)
// 		fd[2] = open(l_input->file_name)
// 		l_input = l_input->next;
// 	}
// }

// static void	init_fd_by_redirection(t_redir_iter *redir_iter, int *fd)
// {
// 	if (redir_iter == NULL)
// 		return ;
// 	init_input_fd(redir_iter->l_input, fd);
// 	init_output_fd(redir_iter->l_output, fd);
// }

void	do_it_child(t_parsing_list *l_parsing, t_args_execve *p_args_execve,
			int *fd, t_info_process *info_proc)
{
	init_execve_args(l_parsing, p_args_execve, p_args_execve->envp);
	// init_fd_by_redirection(l_parsing->redir_iter, fd);
	if (fd[2] != 0)
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

	// if (info_proc->idx_curr_proc != 0)
	// {
	// 	safe_dup2(fd[2], 0);
	// 	safe_close(fd[2]);
	// }
	// if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
	// {
	// 	safe_close(fd[0]);
	// 	safe_dup2(fd[1], 1);
	// 	safe_close(fd[1]);
	// }