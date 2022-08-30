/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipe_and_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:47:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/30 16:44:30 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

pid_t	*pipe_and_fork(t_exec *exec)
{
	int	i;
	pid_t	pid[exec->process_cnt];

	i = 0;
	if (pipe(exec->pipe_fd) == -1)
		return ; // pid 배열의 0, 1인덱스에 값이 채워짐
	while (i < exec->process_cnt) // making pipe
	{
		// 자식 프로세스의 갯수만큼 pid가 생성됨
		exec->process_id[i] = fork();
		if (exec->process_id[0] < 0)
			ft_error();
		if (exec->process_id[0] == 0) // child process
			child_process(exec, i);
		i++;
		exec->pre_read_fd = exec->pipe_fd[0]; // 파이프의 출력값 저장
	}
	return (&pid);
	 // 모든 자식프로세스들의 pid를 담은 배열 리턴
	 // 나중에 waitpid 할때 사용
}
