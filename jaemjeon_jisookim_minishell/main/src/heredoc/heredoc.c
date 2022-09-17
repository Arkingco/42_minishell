/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:13:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 02:36:16 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*make_tmp_filename(void *p1_8byte, void *p2_8byte)
{
	char	*tmp_filename;
	char	*tmp_string[4];
	int		four_byte;

	four_byte = (int)p1_8byte;
	tmp_string[0] = ft_itoa(four_byte);
	tmp_string[1] = ft_itoa(four_byte + 1);
	tmp_string[2] = ft_strjoin(tmp_string[0], tmp_string[1]);
	free(tmp_string[0]);
	free(tmp_string[1]);
	four_byte = (int)p2_8byte;
	tmp_string[0] = ft_itoa(four_byte);
	tmp_string[1] = ft_itoa(four_byte + 1);
	tmp_string[3] = ft_strjoin(tmp_string[0], tmp_string[1]);
	free(tmp_string[0]);
	free(tmp_string[1]);
	tmp_string[0] = ft_strjoin(tmp_string[2], tmp_string[3]);
	return (ft_strjoin("/tmp/minishell", tmp_string[0]));
}

int	make_heredoc_file(t_exec *exec, t_cmd *cur_cmd, t_token *cur_redirect_token)
{
	char	*tmp_filename;
	char	*line;
	int		fd;

	tmp_filename = make_tmp_filename(cur_cmd, cur_redirect_token);
	fd = open(tmp_filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit(1);
	do_heredoc(exec, cur_redirect_token->string_value, fd);
	close(fd);
	return (0);
}

void	rename_string_value(t_exec *exec)
{
	t_cmd	*cur_cmd;
	t_token	*cur_redirect_token;
	int		ret_pid;

	cur_cmd = exec->cmds;
	while (cur_cmd != NULL)
	{
		cur_redirect_token = cur_cmd->redirect_input;
		while (cur_redirect_token != NULL)
		{
			if (cur_redirect_token->type & HEREDOC)
			{
				free(cur_redirect_token->string_value);
				cur_redirect_token->string_value = \
								make_tmp_filename(cur_cmd, cur_redirect_token);
			}
			cur_redirect_token = cur_redirect_token->next;
		}
		cur_cmd = cur_cmd->next;
	}
}

int	heredoc(t_exec *exec, pid_t ret_pid)
{
	t_cmd	*cur_cmd;
	t_token	*cur_redirect_token;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		// signal(SIGINT, heredoc_process_sigint_process); // testing_code
		cur_cmd = exec->cmds;
		while (cur_cmd != NULL)
		{
			cur_redirect_token = cur_cmd->redirect_input;
			while (cur_redirect_token != NULL)
			{
				if (cur_redirect_token->type & HEREDOC)
					ret_pid = make_heredoc_file(exec, cur_cmd, cur_redirect_token);
				cur_redirect_token = cur_redirect_token->next;
			}
			cur_cmd = cur_cmd->next;
		}
		exit(0);
	}
	// signal(SIGINT, doing_heredoc_sigint_process); // testing_code
	ft_wait(1, &pid);
	rename_string_value(exec);
	return (TRUE);
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
