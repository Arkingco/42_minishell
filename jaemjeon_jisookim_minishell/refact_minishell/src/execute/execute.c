/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:48:13 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:23 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


// t_cmd의 simple_cmd문자가 export인걸 확인하고 해당 함수 안으로 들어옴

// redirect input 마지막에 있는 걸 찾아서 엶. 
// 만약 열지 못하면 폴더가 없는거니까 에러처리.

// redirect output 마지막에 있는 걸 찾아서 엶. 
// 만약 열지 못하면 폴더가 없는거니까 에러처리.

void	ft_error(void)
{
	write(2, "Error!\n", 7);
	exit();
	return ;
}

// int	check_redirection(t_exec *exec, t_cmd *cmd)
// {
// 	if (cmd->redirect_input) // < <<
// 	{
// 		if (exec->heredoc_flag)

// 		if (cmd->redirect_input == READ)
// 		{

// 		}
// 	}
// 	if (cmd->redirect_output)
// 	{

// 	}
// }

// void	set_pipe(t_exec->)
// {
// 	if (pipe(exec->pipe_pid) == -1)
// 		ft_error();
// }



void	execute(t_cmd *cmd)
{
	t_exec	*exec;
	
	exec = ft_calloc(1, sizeof(t_exec));
	init_exec(exec, cmd);
	pipe_and_fork(exec, cmd); // child process pid list
	execute();


	// .
	// if (exec->cmds == 1)
	// else if (exec->cmds == 2)
	// else //

	// while (cmd)
	// {
	// 	set_pipe(t_exec->pipe_pid); // make pipe
	// 	fork(t_envlst->key)
	// 	fd_controling(cmd, exec);
	// 	//check_redirection(exec, cmd);	// check if has redirection
	// 	//check_simple_cmd(cmd);	// check if has built in / or not
	// 	execute(cmd);
	// 	cmd = cmd->next;
	// }

	return ;
}


void	do_execute(t_envlst *env, t_cmd *cmd,t_exec *exec, char *argv_cmd)
{
	int	flag;

	flag = 0;
	exec->cmds = cmd->simple_cmd;
	exec->final_path = get_path_lst(env, exec); // path 파싱해서 가져온 값
	if (exec->final_path == NULL)
		exec->final_path = exec->cmds[0];
	flag = execve(exec->final_path, exec->cmds, exec->envp);
	if (flag < 0)
		ft_error("Exit with error due to execve() or command not found! ", 127);
}
