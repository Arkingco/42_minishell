/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:47:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/31 14:42:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_and_fork(t_exec *exec, t_cmd *cmd)
{
	pid_t	pid[exec->process_cnt];

	pid = {0,};
	ft_pipe(exec->pipe_fd); // pid 배열의 0, 1인덱스에 값이 채워짐
	exec->pid_lst = &pid;
	exec_fork(exec, cmd, pid);
	if (exec->pipe_fd[0])
		exec->pre_read_fd = exec->pipe_fd[0]; // 파이프의 출력값 저장
}
