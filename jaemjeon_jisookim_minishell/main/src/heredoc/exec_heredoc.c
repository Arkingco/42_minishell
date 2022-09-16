/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 15:43:15 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	heredoc(t_exec *exec)
{
	int		i;
	t_cmd	*cmd;
	t_hdoc	*hdoc;
	pid_t	ret_pid;

	// init struct
	cmd = get_cmd_for_index(exec, 0);
	hdoc = ft_calloc(1, sizeof(t_hdoc));
	if (!hdoc)
		exit (1);

	// heredoc_struct_init
	hdoc->count = exec_count_heredoc(exec, cmd);
	hdoc->limeter_fds = ft_calloc(hdoc->count, sizeof(int *));
	hdoc->limiters = ft_calloc(hdoc->count + 1, sizeof(char *));
	if (!hdoc->limiters || !hdoc->limeter_fds)
		exit (1);
	make_delimiter_array(cmd, hdoc);

	// (forking) open heredoc file and do heredoc
	i = 0;
	while (i < hdoc->count)
	{
		pid = ft_fork();
		if (pid == 0)
		{
			hdoc->delimeter_fds[i] = open_heredoc_file(exec, hdoc->limiters[i], i);	
			exit(0);
		}
		i++;
	}

	// wait in parent process
	ret_pid = ft_wait(hdoc->count, hdoc->child_pid);
	return (ret_pid);
}

// 히어독 실행, fd반환 (open)
int	open_heredoc_file(t_exec *exec, char *limiter, int i)
{
	int		input_fd;
	char	*heredoc_name;
	
	input_fd = 0;
	index_to_string = (char *)(i + '0');
	dprintf(2, "index_to_string : %s\n",index_to_string); // debug
	heredoc_name = ft_strjoin("./TeMp_FiLe", index_to_string);
	input_fd = open(heredoc_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (input_fd == -1)
		exit(1);
	do_heredoc(exec, limiter, input_fd);
	ft_close(input_fd);
	input_fd = open(heredoc_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (input_fd == -1)
		exit(1);
	
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
			ft_putstr_fd("\n", fd);
			free(line);
			line = 0;
		}
		else
			break ;
	}
	return ;
}
