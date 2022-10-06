/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:13:41 by kipark            #+#    #+#             */
/*   Updated: 2022/10/06 11:56:00 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "terminal.h"
#include "here_doc.h"
#include "execution.h"
#include "exit_status.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	get_exit_status(int status)
{
	int	return_code;
	int	signal_number;

	return_code = 0;
	signal_number = 0;
	if (WIFEXITED(status))
		return_code = WEXITSTATUS(status);
	else
	{
		return_code = 128;
		if (WIFSIGNALED(status))
			signal_number = WTERMSIG(status);
		else
		{
			if (WIFSTOPPED(status))
				signal_number = SIGSTOP;
			if (WIFCONTINUED(status))
				signal_number = SIGCONT;
		}			
	}
	return (g_exit_status = return_code + signal_number);
}

void	here_doc_child(char *limiter, int *fd)
{
	char		*line;
	const int	limiter_size = ft_strlen(limiter);

	set_here_doc_sig_handler();
	while (1)
	{
		line = readline("> ");
		if (line)
		{
			if (ft_strncmp(limiter, line, limiter_size + 1) == 0)
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		else
			break ;
	}
	free(line);
	safe_close(fd[0]);
	safe_close(fd[1]);
	exit(0);
}

static t_here_doc	*tour_cmd_redir(t_redir_chunk *cmd_redir, \
														t_here_doc *l_here_doc)
{
	int	fd[2];
	int	pid;
	int	status;

	while (cmd_redir)
	{
		if (cmd_redir->type == T_HERE_DOC)
		{
			safe_pipe(fd);
			pid = safe_fork();
			if (pid == 0)
				here_doc_child(cmd_redir->file_name, fd);
			else
			{
				safe_close(fd[1]);
				wait(&status);
				if (get_exit_status(status) == 1)
					return (free_all_here_doc(l_here_doc, fd[0]));
				else
					add_here_doc(l_here_doc, fd[0]);
			}
		}
		cmd_redir = cmd_redir->next;
	}
	return (l_here_doc);
}

t_here_doc	*init_here_doc(t_parsing_list *l_parsing)
{
	t_here_doc		*l_here_doc;
	t_redir_iter	*this_redir_iter;

	init_terminal(HERE_DOC_TERMINAL);
	l_here_doc = ft_safe_malloc(sizeof(t_here_doc));
	l_here_doc->next = NULL;
	l_here_doc->read_end = 0;
	while (l_parsing)
	{
		this_redir_iter = l_parsing->redir_iter;
		if (this_redir_iter != NULL && this_redir_iter->l_input != NULL)
		{
			if (tour_cmd_redir(this_redir_iter->l_input, l_here_doc) == NULL)
			{
				init_terminal(DEFAULT_TERMINAL);
				return (NULL);
			}
		}
		l_parsing = l_parsing->next;
	}
	init_terminal(DEFAULT_TERMINAL);
	return (l_here_doc);
}
