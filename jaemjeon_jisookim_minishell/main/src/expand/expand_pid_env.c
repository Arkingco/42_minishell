/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_pid_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:11:28 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 18:36:28 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	*cpy_none_expander(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context;
	cpy_end = cpy_start;
	__skip_only_quote_and_letter(&cpy_end);
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start);
	*context = cpy_end;
	return (copied_string);
}

void	get_42_pid(char *pid_suspect, t_token *token)
{
	pid_suspect[0] = '4';
	pid_suspect[1] = '2';
	token->type |= EXPANDED;
}

void	expand_pidenv(t_token *token)
{
	char	*pid_suspect;

	pid_suspect = token->string_value;
	while (1)
	{
		pid_suspect = ft_strchr(pid_suspect, '$');
		if (pid_suspect == NULL)
			break ;
		if (ft_strncmp(pid_suspect, "$$", 2) != 0)
		{
			pid_suspect++;
			continue ;
		}
		else
			get_42_pid(pid_suspect, token);
	}
}
