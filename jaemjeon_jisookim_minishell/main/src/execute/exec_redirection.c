/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:48:04 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 23:01:11 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_redirect_input(t_exec *exec, t_cmd *cmd)
{

	int		infile_fd;
	t_token	*redi;


	infile_fd = 0;
	redi = cmd->redirect_input;
	while (redi)
	{
		infile_fd = open(redi->string_value, O_RDONLY);
		if (infile_fd == -1)
			return (0);
		redi = redi->next;
	}
	ft_dup2(infile_fd, 0);
	ft_close(infile_fd);
	
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
