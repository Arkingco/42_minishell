/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:44:26 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 20:01:19 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_heredoc(t_working_info *info)
{
	t_cmd	*cur_cmd;
	t_token	*cur_input_redirection;

	cur_cmd = info->cmd;
	while (cur_cmd != NULL)
	{
		cur_input_redirection = cur_cmd->redirect_input;
		while (cur_input_redirection != NULL)
		{
			if (cur_input_redirection->type & HEREDOC)
				return (TRUE);
			cur_input_redirection = cur_input_redirection->next;
		}
		cur_cmd = cur_cmd->next;
	}
	return (FALSE);
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
	tmp_filename = ft_strjoin(tmp_string[2], tmp_string[3]);
	free(tmp_string[2]);
	free(tmp_string[3]);
	return (ft_strjoin("/tmp/minishell", tmp_filename));
}

void	rename_string_value(t_working_info *info)
{
	t_cmd	*cur_cmd;
	t_token	*cur_redirect_token;

	cur_cmd = info->cmd;
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
