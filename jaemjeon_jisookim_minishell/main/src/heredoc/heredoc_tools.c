/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:52:32 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 01:56:14 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	doing_heredoc_sigint_process(int signo)
{
	if (signo == SIGINT)
		write(2, "\n", 1);
}

void	heredoc_process_sigint_process(int signo)
{
	if (signo == SIGINT)
		exit(1);
}

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
