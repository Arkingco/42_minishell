/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:44:26 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 21:44:48 by jaemjeon         ###   ########.fr       */
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

char	*filename_join_free(char *s1, char *s2, int *pointer)
{
	char	*result;

	s1 = ft_itoa(*pointer);
	s2 = ft_itoa(*(pointer + 1));
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*make_tmp_filename(void *p1_8byte, void *p2_8byte)
{
	char	*tmp_filename;
	char	*tmp_string[4];
	int		*pointer;
	char	*return_val;

	pointer = (int *)p1_8byte;
	tmp_string[2] = filename_join_free(tmp_string[0], tmp_string[1], pointer);
	pointer = (int *)p2_8byte;
	tmp_string[3] = filename_join_free(tmp_string[0], tmp_string[1], pointer);
	tmp_filename = ft_strjoin(tmp_string[2], tmp_string[3]);
	free(tmp_string[2]);
	free(tmp_string[3]);
	return_val = ft_strjoin("/tmp/minishell", tmp_filename);
	free(tmp_filename);
	return (return_val);
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
