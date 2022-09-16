/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:13:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 18:02:19 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

int	heredoc(t_exec *exec)
{
	int		i;
	pid_t	pid;
	t_hdoc	*hdoc;
	pid_t	ret_pid;

	i = 0;
	pid = 0;
	while (i < hdoc->count)
	{
		hdoc = safe_calloc(1, sizeof(t_hdoc));
		get_info_hdoc_struct(exec, hdoc);
		pid = ft_fork();
		if (pid == 0)
		{
			open_heredoc_file(exec, hdoc, hdoc->limiters[i], i);	
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

void	get_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc)
{
	// heredoc_struct_init
	check_heredoc(exec, hdoc);
	hdoc->limiters = (char **)safe_calloc(hdoc->count, sizeof(char *));
	hdoc->limeter_fds = (int *)safe_calloc(hdoc->count, sizeof(int));
	hdoc->hdoc_pids = (pid_t *)safe_calloc(hdoc->count, sizeof(int *));

	make_heredoc_lilmiter_array(exec, hdoc);

	return ;
}

// 히어독 실행, fd반환 (open)
void	open_heredoc_file(t_exec *exec, t_hdoc *hdoc, char *limiter, int i)
{
	int		input_fd;
	char	*index_to_string;
	
	input_fd = 0;
	index_to_string = ft_itoa(i);
	dprintf(2, "index_to_string : %s\n",index_to_string); // debug
	hdoc->file_name[i] = ft_strjoin("./Te3M_10p_F432iL9e", index_to_string);
	input_fd = open(hdoc->file_name[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (input_fd == -1)
		exit(1);
	do_heredoc(exec, limiter, input_fd);
	ft_close(input_fd);
	input_fd = open(hdoc->file_name[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (input_fd == -1)
		exit(1);
	hdoc->limeter_fds[i] = input_fd;
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
