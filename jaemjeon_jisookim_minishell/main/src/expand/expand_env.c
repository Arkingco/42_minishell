/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:02:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 18:33:33 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*expanded_string;

	cpy_start = *context;
	cpy_end = cpy_start + 1;
	if (__is_to_remove_dollar(token, cpy_end))
		expanded_string = ft_strdup("");
	else if (*cpy_end == '?')
	{
		expanded_string = ft_itoa(g_errno);
		cpy_end++;
	}
	else
	{
		expanded_string = __get_envvalue(cpy_start, &cpy_end, env);
		token->type |= EXPANDED;
	}
	*context = cpy_end;
	return (expanded_string);
}

void	expand_env(t_token *token, t_envlst *env)
{
	char	*cpy_start;
	char	*result;
	char	*copied_string;

	cpy_start = token->string_value;
	result = ft_strdup("");
	while (*cpy_start != '\0')
	{
		if (*cpy_start == '$')
			copied_string = expand_env_withdollar(token, env, &cpy_start);
		else if (ft_is_ifs(cpy_start))
			copied_string = cpy_ifs_string(&cpy_start);
		else
			copied_string = cpy_none_expander(&cpy_start);
		result = raise_buffer(result, ft_strlen(copied_string));
		ft_strlcat(result, copied_string, \
							ft_strlen(result) + ft_strlen(copied_string) + 1);
		free(copied_string);
		copied_string = 0;
	}
	free(token->string_value);
	token->string_value = result;
}
