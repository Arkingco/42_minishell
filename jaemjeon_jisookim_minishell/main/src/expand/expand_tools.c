/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 02:07:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 18:36:57 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env)
{
	char	*expanded_string;
	char	*env_key;
	char	*env_value;

	__skip_envkey(envkey_end);
	if (doller_p + 1 == *envkey_end)
	{
		expanded_string = ft_strdup("$");
		return (expanded_string);
	}
	else
	{
		env_key = ft_substr(doller_p, 1, *envkey_end - doller_p - 1);
		env_value = ft_getenv(env, env_key);
		if (env_value != NULL)
			expanded_string = ft_strdup(env_value);
		else
			expanded_string = ft_strdup("");
		free(env_key);
		env_key = 0;
		return (expanded_string);
	}
}

char	*raise_buffer(char *prev, int raise_size)
{
	char	*raised_buffer;

	raised_buffer = (char *)ft_calloc(1, ft_strlen(prev) + raise_size + 1);
	if (raised_buffer == NULL)
	{
		free(raised_buffer);
		ft_error_exit(1, "exit with malloc error");
	}
	ft_strlcpy(raised_buffer, prev, ft_strlen(prev) + 1);
	free(prev);
	prev = 0;
	return (raised_buffer);
}
