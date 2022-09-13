/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:48:04 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 18:04:20 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_redirect_input(t_exec *exec, t_cmd *cmd)
{
	char	*infile;
	int		infile_fd;
	int		type;
	t_token	*redi;
	t_token *redi_head;

	infile_fd = 0;
	type = 0;
	redi = cmd->redirect_input;
	redi_head = redi;
	infile = get_redi_execute_file(exec, redi, &type);
	// dprintf(STDERR_FILENO, " STDIN => %s\n", infile);
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

int	handle_redirect_output(t_exec *exec, t_cmd *cmd)
{
	char	*outfile;
	int		outfile_fd;
	int		type;
	t_token	*redi;
	t_token *redi_head;

	outfile_fd = 0;
	type = 0;
	redi = cmd->redirect_output;
	redi_head = redi;
	outfile = get_redi_execute_file(exec, redi, &type);
	// dprintf(STDERR_FILENO, " STDOUT => %s\n", outfile);
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

void	exec_handle_redirection(t_exec *exec, t_cmd *cmd)
{
	if (cmd && cmd->redirect_input)
		handle_redirect_input(exec, cmd);

	if (cmd && cmd->redirect_output)
		handle_redirect_output(exec, cmd);

	return ;
}
