/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redi_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:26:17 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/11 00:00:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_redi_heredoc(t_exec *exec, char *limiter, int *fd)
{
	*fd = open("here_docs", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
		exit (1);
	do_heredoc(exec, limiter, *fd);
	ft_close(*fd);
	ft_open("here_docs", O_RDONLY);
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

void	redi_open_before_exec_file(t_exec *exec, t_token *redi)
{
	int	fd;

	while (redi->string_value)
	{
		if (!redi->next) // (== last redi)
		{
			return ;
		}
		else
		{
			fd = ft_open(redi->string_value, O_RDONLY); // open files
			ft_close(fd); // close files
			redi = redi->next;
		}
	}
	return ;
}

char	*exec_find_redi_file(t_exec *exec, t_token *redi, int *more_redi_flag)
{
	t_token	*redi_head;

	redi_head = redi;
	while (redi->string_value)
	{
		if (!redi->next)
		{
			redi = redi_head;
			return (redi->string_value);
		}
		else
		{
			redi = redi->next;
			*more_redi_flag = 1;
		}
	}
	return (NULL);
}

// change input, output file stream by using dup2
char	*get_redi_execute_file(t_exec *exec, t_token *redi, int i, int *type)
{
	t_token	*redi_head;
	char	*is_exec_file;
	int		more_redi_flag;
	int		exec_file_fd;

	redi_head = redi;
	is_exec_file = NULL;
	more_redi_flag = 0;
	is_exec_file = exec_find_redi_file(exec, redi, &more_redi_flag); //find exec file
	
	if (!is_exec_file)
		return (0);
	if (more_redi_flag)
	{
		redi_open_before_exec_file(exec, redi); //open file before exec file executes.
	}
	*type = redi->type;
	redi = redi_head;
	return (is_exec_file);
}

