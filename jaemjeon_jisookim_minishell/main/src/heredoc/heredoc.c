/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:44:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/19 22:27:39 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_input_heredoc(t_working_info *info, char *delimiter, int fd)
{
	// char	*line;

	// while (1)
	// {
	// 	line = readline("> ");
	// 	if (line == NULL || ft_strncmp(line, delimiter, INT_MAX))
	// 	{
			
	// 	}
	// 	else
	// 	{

	// 	}
	// }
}

char	*make_tmp_filename(t_cmd *cmd, t_token *cur_redirection)
{
	return (NULL);
}

void	process_cur_heredoc(t_working_info *info, t_cmd *cur_cmd, \
													t_token *cur_redirection)
{
	char	*tmp_filename;
	char	*line;
	int		fd;

	tmp_filename = make_tmp_filename(cur_cmd, cur_redirection);
	if (tmp_filename == NULL)
	{
		perror("malloc_fail in heredoc");
		exit(FAIL);
	}
	fd = open(tmp_filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open_fail in heredoc");
		exit(FAIL);
	}
	get_input_heredoc(info, cur_redirection, fd);
	close(fd);
	return (0);
}

void	process_heredoc(t_working_info *info)
{
	t_cmd	*cur_cmd;
	t_token	*cur_redirection;

	cur_cmd = info->cmd;
	while (cur_cmd != NULL)
	{
		cur_redirection = cur_cmd->redirect_input;
		while (cur_redirection != NULL)
		{
			if (cur_redirection->type & HEREDOC)
				process_cur_heredoc(info, cur_cmd, cur_redirection);
			cur_redirection = cur_redirection->next;
		}
		cur_cmd = cur_cmd->next;
	}
}

int	heredoc(t_working_info *info)
{
	pid_t	pid;

	sigtermset(HEREDOC_PARENT);
	pid = fork();
	if (pid == 0)
	{
		sigtermset(HEREDOC_CHILD);
		process_heredoc(info);
		exit(0);
	}
	ft_wait(1, &pid);
	sigtermset(MINISHELL_NO_CHILD);
	rename_string_value(info);
	return (TRUE);
}