/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:13:41 by kipark            #+#    #+#             */
/*   Updated: 2022/10/02 20:06:23 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "here_doc.h"
#include "execution.h"
#include "exit_status.h"
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	init_exit_status(int status)
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
	g_exit_status = return_code + signal_number;
}

t_here_doc *new_here_doc(int fd)
{
	t_here_doc *here_doc;

	here_doc = ft_safe_malloc(sizeof(t_here_doc));
	here_doc->read_end = fd;
	here_doc->next = NULL;
}

void add_here_doc(t_here_doc *here_doc, int fd)
{
	t_here_doc *this_here_doc;

	this_here_doc = here_doc->next;
	while (this_here_doc)
	{
		this_here_doc = this_here_doc->next;
	}
	this_here_doc->next = nwe_here_doc(fd);
}

void run_here_doc_child(char *limiter, int *fd)
{
	char	*str;
	const int limiter_size = ft_strlen(limiter);

	set_terminal_sighadle();
	while(1)
	{
		str = readline("> ");
		if (ft_strncmp(limiter, str, limiter_size + 1) == 0)
			break;
		write(fd[1], str, ft_strlen(str));
	}
	safe_close(fd[0]);
	safe_close(fd[1]);
	return ;
}

void run_here_doc_parent(t_here_doc *l_here_doc, int *fd)
{
	int status;

	safe_close(fd[1]);
	wait(&status);
	if (status == SIGINT)
		return(free_all_hereDock(l_here_doc));
	else
		add_here_doc(l_here_doc, fd[0]);
}

void	run_here_doc_cmd(t_parsing_list *this_cmd, t_here_doc *l_here_doc)
{
	t_redir_chunk	*this_cmd_redir;
	int				fd[2];
	int				pid;

	this_cmd_redir = this_cmd->redir_iter->l_input;
	while (this_cmd_redir)
	{
		if (ft_strncmp(this_cmd_redir->redir, "<<", 3) == 0)
		{
			safe_pipe(fd);
			pid = safe_fork();
			if(pid == 0)
				run_here_doc_child(this_cmd_redir->file_name, fd);
			else
				run_here_doc_parent(l_here_doc, fd);
		}
		this_cmd_redir = this_cmd_redir->next;
	}
}

t_here_doc *init_here_doc(t_parsing_list *l_parsing)
{
	t_parsing_list	*this_cmd;
	t_here_doc		*l_here_doc;

	l_here_doc = ft_safe_malloc(l_here_doc);
	l_here_doc->next = NULL;
	l_here_doc->read_end = 0;
	this_cmd = l_parsing;
	while (this_cmd)
	{
		run_here_doc_this_cmd(this_cmd, l_here_doc);
		this_cmd = this_cmd->next;
	}
	return (NULL);
}
