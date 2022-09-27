/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:38:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/27 21:56:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "env.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"

// printf
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

static void	update_fd_for_pipe(t_info_fd *p_fd, t_info_process *info_proc)
{
	if (p_fd->pipefd[0] == -1)
		return ;
	if (info_proc->idx_curr_proc != 0)
		p_fd->updated_fd.input = p_fd->pipefd[0];
	if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
		p_fd->updated_fd.output = p_fd->pipefd[1];
}

static void	safe_dup2(int from, int to)
{
	int	ret;

	ret = dup2(from, to);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
}

static void	safe_close(int fd)
{
	int	ret;

	ret = close(fd);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
}

static void	do_it_child(t_parsing_list *l_parsing, t_args_execve *p_args_execve,
				t_info_fd *p_fd, t_info_process *info_proc)
{
	init_execve_args(l_parsing, p_args_execve, p_args_execve->envp);
	update_fd_for_pipe(p_fd, info_proc);
	// redirection 이 존재하는지 않는지?
	// dup2
	printf("curr: %zu, last: %zu\n", info_proc->idx_curr_proc, info_proc->num_proc);
	if (info_proc->idx_curr_proc != 0)
	{
		//
		printf("pipefd: %d\n", p_fd->pipefd[0]);
		safe_dup2(p_fd->pipefd[0], 0);
		safe_close(p_fd->pipefd[0]);
	}
	// if (info_proc->idx_curr_proc != info_proc->num_proc - 1)
	// {
	// 	safe_dup2(p_fd->pipefd[1], 1);
	// 	safe_close(p_fd->pipefd[1]);
	// }
	execve_cmd(p_args_execve, p_args_execve->envp);
}

static void	safe_pipe(int *fd)
{
	int	ret;

	ret = pipe(fd);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
}

static void	init_fd(t_info_fd *fd)
{
	fd->updated_fd.input = 0;
	fd->updated_fd.output = 1;
	fd->pipefd[0] = -1;
	fd->pipefd[1] = -1;
}

static size_t	count_the_number_of_processes(t_parsing_list *l_parsing)
{
	size_t	num;

	num = 0;
	while (l_parsing)
	{
		num++;
		l_parsing = l_parsing->next;
	}
	return (num);
}

void	execute_cmd(t_parsing_list *l_parsing, t_env *l_env)
{
	t_args_execve	args_execve;
	t_info_fd		info_fd;
	t_info_process	info_proc;
	
	if (is_single_cmd(l_parsing->next) && is_built_in(l_parsing->l_simple_cmd))
	{
		printf("single built_in cmd\n");
		execute_bulit_in(l_parsing->l_simple_cmd, l_env, SINGLE_CMD);
	}
	else
	{
		info_proc.idx_curr_proc = 0;
		info_proc.num_proc = count_the_number_of_processes(l_parsing);
		l_env = l_env->next;
		args_execve.envp = init_curr_envp(l_env);
		while (l_parsing)
		{
			init_fd(&info_fd);
			if (l_parsing->next)
				safe_pipe(info_fd.pipefd);
			//
			printf("fadsklfhajklshflkah: %d\n", info_fd.pipefd[0]);
			info_proc.pid = safe_fork();
			if (info_proc.pid == 0)
				do_it_child(l_parsing, &args_execve, &info_fd, &info_proc);
			// else
				// do_it_parent();
			info_proc.idx_curr_proc++;
			l_parsing = l_parsing->next;
		}
		wait_all_child(info_proc.pid, info_proc.num_proc);
		ft_safe_free(args_execve.envp);
	}
}
