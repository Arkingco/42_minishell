/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 21:57:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_check_heredoc(t_exec *exec, int i)
{
	int		input_fd;
	char	*limiter;

	limiter = 0;
	input_fd = -1;
	tools_move_cmd(exec, i);
	if (exec->cmds && exec->cmds->redirect_input)
	{
		if (exec->cmds->redirect_input->type & HEREDOC)
		{
			limiter = exec->cmds->redirect_input->string_value;
			input_fd = exec_redi_heredoc(exec, limiter);
			exec->here_doc_flag = 1;
		}
		else
			exec->here_doc_flag = 0;
	}
	exec->cmds = exec->cmd_head;
	return (input_fd);
}

int	exec_redi_heredoc(t_exec *exec, char *limiter)
{
	int	input_fd;
	
	input_fd = 0;
	input_fd = open("here_docs", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (input_fd == -1)
		exit(1);
	
	do_heredoc(exec, limiter, input_fd);
	ft_close(input_fd);
	input_fd = ft_open("here_docs", O_RDONLY);
	
	return (input_fd);
}

void	do_heredoc(t_exec *exec, char *limiter, int fd)
{
	char	*line;

	line = 0;
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		dprintf(2, "line : %s\n", line);
		if (line)
		{
			line[ft_strlen(line) - 1] = '\0';
			if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			{
				free(line);
				line = 0;
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
			line = 0;
		}
		else
			break ;
	}
	return ;
}
