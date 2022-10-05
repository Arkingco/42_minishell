/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/05 15:54:27 by jayoon           ###   ########.fr       */
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

static int	safe_open(char *path, int oflag)
{
	int	fd;
	
	fd = 0;
	if (oflag == O_RDONLY)
	{
		fd = open(path, oflag);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	else if (oflag == (O_TRUNC | O_WRONLY | O_CREAT))
	{
		fd = open(path, oflag, 0666);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	else
	{
		fd = open(path, oflag, 0666);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
	}
	return (fd);
}

static void	init_input_fd(t_redir_chunk *l_input, int *fd)
{
	if (fd[2] != 0)
		safe_close(fd[2]);
	while (l_input)
	{
		if (l_input->type == T_INPUT_REDIR)
			fd[2] = safe_open(l_input->file_name, O_RDONLY);
		else
		{
		}
		if (l_input->next)
			safe_close(fd[2]);
		l_input = l_input->next;
	}
}

static void	init_output_fd(t_redir_chunk *l_output, int *fd)
{
	if (fd[1] != 1)
		safe_close(fd[1]);
	while (l_output)
	{
		if (l_output->type == T_OUTPUT_REDIR)
			fd[1] = safe_open(l_output->file_name,
						O_TRUNC | O_WRONLY | O_CREAT);
		else
			fd[1] = safe_open(l_output->file_name,
						O_APPEND | O_WRONLY | O_CREAT);
		if (l_output->next)
			safe_close(fd[1]);
		l_output = l_output->next;
	}
}

static void	init_fd_by_redirection(t_redir_iter *redir_iter, int *fd)
{
	if (redir_iter->l_input)
		init_input_fd(redir_iter->l_input, fd);
	if (redir_iter->l_output)
		init_output_fd(redir_iter->l_output, fd);
}

void	do_it_child(t_parsing_list *l_parsing, t_args_execve *p_args_execve,
			int *fd, t_info_process *info_proc)
{
	if (l_parsing->redir_iter)
		init_fd_by_redirection(l_parsing->redir_iter, fd);
	if (fd[0] != 0 && info_proc->idx_curr_proc != info_proc->num_proc - 1)
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
		init_execve_args(l_parsing, p_args_execve, p_args_execve->envp);
		execve_cmd(p_args_execve, p_args_execve->envp);
	}
	exit(0);
}
