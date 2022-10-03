/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:13:41 by kipark            #+#    #+#             */
/*   Updated: 2022/10/03 20:01:33 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
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
		return_code = 127;
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

void here_doc_child(char *limiter, int *fd)
{
	char		*line;
	char		*pipe_line;
	const int 	limiter_size = ft_strlen(limiter);

	set_here_doc_sig_handler();
	while(1)
	{
		line = readline("> ");
		if (line)
		{
			if (ft_strncmp(limiter, line, limiter_size + 1) == 0)
			{
				free(line);
				break;
			}
			pipe_line = ft_safe_strjoin(line, "\n");
			write(fd[1], pipe_line, ft_strlen(pipe_line));
			free(pipe_line);
			free(line);
		}
		else
		{
			free(line);
			break ;
		}
	}
	// test
		// char buffer[100];
		// read(fd[0], buffer, 100);
		// printf("%s", buffer);
	// ------------------------
	safe_close(fd[0]);
	safe_close(fd[1]);
	exit(0);
}

void	tour_parsing_cmd_redir(t_redir_chunk *cmd_redir, t_here_doc *l_here_doc)
{
	int				fd[2];
	int				pid;
	int				status;

	while (cmd_redir)
	{
		if (ft_strncmp(cmd_redir->redir, "<<", 3) == 0)
		{
			safe_pipe(fd);
			pid = safe_fork();
			if(pid == 0)
				here_doc_child(cmd_redir->file_name, fd);
			else
			{
				safe_close(fd[1]);
				wait(&status);
				if (get_exit_status(status) == 1)
					return(free_all_here_doc(l_here_doc));
				else
					add_here_doc(l_here_doc, fd[0]);	
			}
		}
		cmd_redir = cmd_redir->next;
	}
}

t_here_doc *init_here_doc(t_parsing_list *l_parsing)
{
	t_parsing_list	*this_cmd;
	t_here_doc		*l_here_doc;

	l_here_doc = ft_safe_malloc(sizeof(t_here_doc));
	l_here_doc->next = NULL;
	l_here_doc->read_end = 0;
	this_cmd = l_parsing;
	while (this_cmd)
	{
		if (this_cmd->redir_iter != NULL && \
										this_cmd->redir_iter->l_input != NULL)
			tour_parsing_cmd_redir(this_cmd->redir_iter->l_input, l_here_doc);
		this_cmd = this_cmd->next;
	}
	return (l_here_doc);
}
