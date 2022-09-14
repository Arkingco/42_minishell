/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/14 15:06:39 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_check_heredoc(t_exec *exec)
{
	int		i;
	int		input_fd;
	char	*limiter;
	t_cmd	*cmd;
	t_hdoc	*hdoc;

	i = 0;
	limiter = 0;
	input_fd = -1;
	cmd = get_cmd_for_index(exec, 0);
	hdoc = ft_calloc(1, sizeof(t_hdoc));
	if (!hdoc)
		exit (1);

	hdoc->count = exec_count_heredoc(exec, cmd);
	hdoc->delimiter_arr = ft_calloc(hdoc->count + 1, sizeof(char *));
	if (!hdoc->delimiter_arr)
		exit (1);

	if (cmd && cmd->redirect_input)
	{
		if (cmd->redirect_input->type & HEREDOC)
		{
			hdoc->delimiter_arr[i] = cmd->redirect_input->string_value;
			input_fd = exec_redi_heredoc(exec, hdoc->delimiter_arr[i]);
			i++;
		}
		i++;
	}
	return (input_fd);
}

// 히어독 수 가져오는 함수 int	exec_count_heredoc(t_exec *exec, t_cmd *cmd, t_hdoc *hdoc)
{
	int i;
	int	result;

	i = 0;
	result = 0;
	if (cmd && cmd->redirect_input)
	{
		if (cmd->redirect_input->type & HEREDOC)
		{
			result++;
			
		}
		i++;
	}
	return (result);
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
		if (line)
		{
			line[ft_strlen(line) - 1] = '\0';
			if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			{
				free(line);
				line = 0;
				break ;
			}
			ft_putstr_fd(line, fd);
			write(fd, "\n", 1);
			free(line);
			line = 0;
		}
		else
			break ;
	}
	return ;
}
