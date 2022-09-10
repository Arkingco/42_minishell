/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:48:04 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/10 16:07:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_redirect_input(t_exec *exec, int process_number)
{
	char	*infile;
	int		infile_fd;
	t_token	*redi;

	dprintf(2, "=== this is input redi!! === \n");
	infile_fd = 0;
	redi = exec->cmds->redirect_input;
	infile = get_redi_execute_file(exec, redi, process_number);
	
	infile_fd = ft_open(infile, O_RDONLY, -1); //execute last file
	dprintf(2, "**** infile_fd : [%d] ****\n", infile_fd);
	ft_dup2(infile_fd, 0);
	ft_close(infile_fd);
	
	exec->redirect[0] = 0;
	return ;
}

void	handle_redirect_output(t_exec *exec, int process_number)
{
	char	*outfile;
	int		outfile_fd;
	t_token	*redi;


	dprintf(2, "=== this is output redi!! === \n");
	outfile_fd = 0;
	redi = exec->cmds->redirect_output;
	outfile = get_redi_execute_file(exec, redi, process_number);
	
	outfile_fd = ft_open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dprintf(2, "**** outfile_fd : %d ****\n", outfile_fd);
	ft_dup2(outfile_fd, 1);
	ft_close(outfile_fd);
	
	exec->redirect[1] = 0;
	return ;
}

void	handle_redirection(t_exec *exec, int process_number)
{
	if (exec->redirect[0])
		handle_redirect_input(exec, process_number);
	if (exec->redirect[1])
		handle_redirect_output(exec, process_number);

	return ;
}

void	check_redirection(t_exec *exec)
{

	if (exec->cmds->redirect_input)
	{
		exec->redirect[0] = 1;
	}
	if (exec->cmds->redirect_output)
	{
		exec->redirect[1] = 1;
	}
	return ;
}

void	exec_handle_redirection(t_exec *exec, int process_number)
{
	
	tools_move_cmd(exec, process_number); // process number 만큼 돌리기
	check_redirection(exec); // 리다이렉션 유무 체크

	if (exec->redirect[0] || exec->redirect[1])
		handle_redirection(exec, process_number);
	
	exec->cmds = exec->cmd_head; // 원상복구!
	
	return ;
}
