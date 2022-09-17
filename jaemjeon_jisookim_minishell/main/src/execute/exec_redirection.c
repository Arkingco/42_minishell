/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:48:04 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 01:44:49 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_infile_redi_valid(t_cmd *cmd, int *infile_fd)
{
	t_token	*redi;
	
	redi = cmd->redirect_input;
	while (redi)
	{
		*infile_fd = open(redi->string_value, O_RDONLY);
		if (*infile_fd == -1)
		{
			ft_putstr_fd(redi->string_value, 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		redi = redi->next;
	}
	return ;
}

void	check_outfile_redi_valid(t_cmd *cmd, int type, int *outfile_fd)
{
	t_token	*redi;
	
	redi = cmd->redirect_output;
	while (redi)
	{
		if (type & WRITE)
			*outfile_fd = open(redi->string_value, \
										O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (type & WRITE_APPEND)
			*outfile_fd = open(redi->string_value, \
										O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*outfile_fd == -1)
		{
			exec_error_exit(redi->string_value);
		}
		redi = redi->next;
	}
	return ;
}

int	handle_redirect_input(t_exec *exec, t_cmd *cmd)
{
	int		infile_fd;
	
	infile_fd = -1;
	check_infile_redi_valid(cmd, &infile_fd);
	ft_dup2(infile_fd, 0);
	ft_close(infile_fd);
	
	return (0);
}

int	handle_redirect_output(t_exec *exec, t_cmd *cmd)
{
	char	*outfile;
	int		outfile_fd;
	int		type;

	outfile_fd = -1;
	type = 0;
	check_outfile_redi_valid(cmd, type, &outfile_fd);
	ft_dup2(outfile_fd, 1);
	ft_close(outfile_fd);
	
	return (0);
}

void	exec_handle_redirection(t_exec *exec, t_cmd *cmd, int i)
{

	cmd = get_cmd_for_index(exec, i);
	if (cmd && cmd->redirect_input)
		handle_redirect_input(exec, cmd);

	if (cmd && cmd->redirect_output)
		handle_redirect_output(exec, cmd);

	return ;
}
