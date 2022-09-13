/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:48:04 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 11:26:51 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"



int	handle_redirect_input(t_exec *exec, int process_number)
{
	char	*infile;
	int		infile_fd;
	int		type;
	t_token	*redi;
	t_token *redi_head;

	infile_fd = 0;
	type = 0;
	redi = exec->cmds->redirect_input;
	redi_head = redi;
	infile = get_redi_execute_file(exec, redi, process_number, &type);
	if (type & HEREDOC)
	{
		infile_fd = exec_check_heredoc(exec, 0);
	}
	else if (type & READ)
	{
		infile_fd = open(infile, O_RDONLY, 0644);
	}
	if (infile_fd == -1)
		return (0);
	ft_dup2(infile_fd, 0);
	ft_close(infile_fd);
	redi = redi_head;
	
	return (0);
}

int	handle_redirect_output(t_exec *exec, int process_number)
{
	char	*outfile;
	int		outfile_fd;
	int		type;
	t_token	*redi;
	t_token *redi_head;

	outfile_fd = 0;
	type = 0;
	redi = exec->cmds->redirect_output;
	redi_head = redi;
	outfile = get_redi_execute_file(exec, redi, process_number, &type);
	if (type & WRITE)
	{
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (type & WRITE_APPEND)
	{
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (outfile_fd == -1)
		return (0);
	ft_dup2(outfile_fd, 1);
	ft_close(outfile_fd);
	redi = redi_head;
	
	return (0);
}

void	exec_handle_redirection(t_exec *exec, int i)
{
	tools_move_cmd(exec, i); // process number 만큼 돌리기
	
	if (exec->cmds && exec->cmds->redirect_input)
		handle_redirect_input(exec, i);

	if (exec->cmds && exec->cmds->redirect_output)
		handle_redirect_output(exec, i);
	
	exec->cmds = exec->cmd_head; 
	
	return ;
}
