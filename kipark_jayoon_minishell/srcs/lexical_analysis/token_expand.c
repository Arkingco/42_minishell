
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:18:15 by kipark            #+#    #+#             */
/*   Updated: 2022/08/23 11:37:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "stdlib.h"
#include "libft.h"
#include "env.h"
#include <stdio.h> 

static char	*expand_and_join_words(t_env *env_head, char *str, int *i)
{
	int		env_key_size;
	char	*env_key;
	char	*env_value;
	char	*expand_str;
	char	*after_str;

	env_key_size = get_env_key_size(str);
	env_key = ft_safe_substr(str, 0, env_key_size);
	env_value = get_env_value(env_head, env_key);
	after_str = ft_safe_substr(str, env_key_size, ft_strlen(str));
	*i = *i + ft_strlen(env_value) - 1;
	expand_str = ft_safe_strjoin(env_value, after_str);
	free(env_value);
	free(env_key);
	free(after_str);
	return (expand_str);
}

void	expand_and_join_before_after_words(t_env *env_head, char **str, int *i)
{
	char	*temp_str;
	char	*before_str;
	char	*after_str;

	temp_str = *str;
	before_str = ft_safe_substr(*str, 0, *i);
	after_str = expand_and_join_words(env_head, *str + *i + 1, i);
	*str = ft_safe_strjoin(before_str, after_str);
	free(temp_str);
	free(before_str);
	free(after_str);
}

char	*expand_this_word_token(t_env *env_head, char *expand_str)
{
	int	i;

	i = 0;
	while (expand_str[i] != '\0')
	{
		if (expand_str[i] == M_SINGLE_QUOTE)
			pass_sigle_quote(expand_str, &i);
		else
			if (expand_str[i] == M_DOLLAR_EXPAND)
				expand_and_join_before_after_words(env_head, &expand_str, &i);
		++i;
	}
	return (expand_str);
}


static int	set_word_token_return_index(char *rl, int i)
{
	while (rl[i + 1] != '\0')
	{
		if (rl[i] == M_SINGLE_QUOTE)
			i = get_quote_type_return_index(rl, i + 1, T_SINGLE_QUOTE);
		else if (rl[i] == M_DOUBLE_QUOTE)
			i = get_quote_type_return_index(rl, i + 1, T_DOUBLE_QUOTE);
		if (ft_isifs(rl[i + 1]) || rl[i + 1] == '\0')
			return (i);
		++i;
	}
	return (i);
}

void	word_token_add(t_token *token_head, t_token_type t_type, \
															char *expand_str)
{
	int				start;
	int				end;

	start = 0;
	end = 0;
	while (expand_str[end] != '\0')
	{
		end = pass_ifs(expand_str, end);
		if (expand_str[end] == '\0')
			break ;
		start = end;
		end = set_word_token_return_index(expand_str, end);
		token_add(token_head, t_type, ft_safe_substr(expand_str, \
													start, end - start + 1));
		end++;
	}
	free(expand_str);
}