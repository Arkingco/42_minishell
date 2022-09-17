/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:13:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 10:39:49 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

int	heredoc(t_exec *exec, pid_t ret_pid)
{
	int		i;
	pid_t	pid;
	t_hdoc	*hdoc;

	pid = 0;
	dprintf(2, "==debug 999===\n");
	hdoc = safe_calloc(1, sizeof(t_hdoc)); // make hdoc struct
	dprintf(2, "==debug 888===\n");
	if (!init_info_hdoc_struct(exec, hdoc)); // if hdoc->count != 0, init hdoc struct
		return (ret_pid);
	dprintf(2, "==debug 000===\n");
	i = 0;
	while (i < hdoc->count)
	{
		dprintf(2, "==debug 111===\n");
		make_and_open_hdoc(exec, hdoc, hdoc->limiters[i], i);
		dprintf(2, "==debug 222===\n");
		pid = ft_fork(); // fork so it can get signal
		dprintf(2, "==debug 333===\n");
		if (pid == 0)
		{
			do_heredoc(exec, hdoc->limiters[i], hdoc->limiter_fds[i]);
			close_and_reopen_hdoc(exec, hdoc, i);
			exit(0);
		}
		hdoc->hdoc_pids[i] = pid;
		i++;
	}
	ret_pid = ft_wait(hdoc->count, hdoc->hdoc_pids); // wait in parent process
	while (i)
	{
		unlink(hdoc->file_name[i]);
		i--;
	}
	return (ret_pid);
}


// 히어독 실행, fd반환 (open)
void	make_and_open_hdoc(t_exec *exec, t_hdoc *hdoc, char *limiter, int i)
{
	int		input_fd;
	char	*index_to_string;
	
	input_fd = 0;
	index_to_string = ft_itoa(i);
	//dprintf(2, "index_to_string : %s\n",index_to_string); // debug
	hdoc->file_name[i] = ft_strjoin("./Te3M_10p_F432iL9e", index_to_string);
	input_fd = open(hdoc->file_name[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (input_fd == -1)
		exit(1);
	hdoc->limiter_fds[i] = input_fd;
	return ;
}

void	close_and_reopen_hdoc(t_exec *exec, t_hdoc *hdoc, int i)
{
	char	*index_to_string;
	
	ft_close(hdoc->limiter_fds[i]);
	hdoc->limiter_fds[i] = open(hdoc->file_name[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (hdoc->limiter_fds[i] == -1)
		exit(1);
	return ;
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
