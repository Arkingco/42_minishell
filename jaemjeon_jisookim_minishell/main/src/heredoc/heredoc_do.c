/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:58:13 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 15:00:14 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc_expand(t_working_info *info, char *line)
{
	t_token	tmp_token_to_expand;

	ft_memset(&tmp_token_to_expand, 0, sizeof(t_token));
	tmp_token_to_expand.string_value = line;
	tmp_token_to_expand.type = WORD;
	expand_pidenv(&tmp_token_to_expand);
	expand_env(&tmp_token_to_expand, info->env);
	return (tmp_token_to_expand.string_value);
}

void	get_input_heredoc(t_working_info *info, t_token *redirec_token, int fd)
{
	const char	*delimiter = redirec_token->string_value;
	char		*line;
	char		*expanded_line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		else if (ft_strncmp(line, delimiter, INT_MAX) == 0)
		{
			free(line);
			break ;
		}
		else
		{
			if (!(redirec_token->type & QUOTE))
			{
				expanded_line = heredoc_expand(info, line);
				ft_putendl_fd(expanded_line, fd);
				free(expanded_line);
			}
			else
			{
				ft_putendl_fd(line, fd);
				free(line);
			}
		}
	}
}
