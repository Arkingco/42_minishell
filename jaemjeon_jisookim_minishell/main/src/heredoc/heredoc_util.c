/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:44:26 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/26 19:01:14 by jaemjeon         ###   ########.fr       */
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

char	*filename_join_free(int *pointer)
{
	char	*result;
	char	*tmp_string[2];

	tmp_string[0] = ft_itoa(*pointer);
	tmp_string[1] = ft_itoa(*(pointer + 1));
	result = ft_strjoin(tmp_string[0], tmp_string[1]);
	free(tmp_string[0]);
	free(tmp_string[1]);
	return (result);
}

char	*make_tmp_filename(void *p1_8byte, void *p2_8byte)
{
	char	*tmp_filename;
	char	*tmp_string[2];
	int		*pointer;
	char	*return_val;

	pointer = (int *)p1_8byte;
	tmp_string[0] = filename_join_free(pointer);
	if (tmp_string[0] == NULL)
		return (NULL);
	pointer = (int *)p2_8byte;
	tmp_string[1] = filename_join_free(pointer);
	if (tmp_string[1] == NULL)
	{
		free(tmp_string[0]);
		return (NULL);
	}
	tmp_filename = ft_strjoin_triple("minishell", tmp_string[0], tmp_string[1]);
	free(tmp_string[0]);
	free(tmp_string[1]);
	if (tmp_filename == NULL)
		return (NULL);
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
