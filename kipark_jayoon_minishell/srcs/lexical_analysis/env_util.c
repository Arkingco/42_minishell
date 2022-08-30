/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/08/30 15:25:45 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"env.h"
#include <stdio.h>

static int	get_env_equal_location(char *env_str)
{
	int	i;

	i = 0;
	while (env_str[i] != '=')
		++i;
	return (i);
}

char *get_env_value(t_env *env_head, char *env_key)
{
	t_env 	*env_list;
	char	*env_str;
	int 	env_str_equal_location;

	env_list = env_head->next;
	while (env_list)
	{
		env_str = env_list->str;
		env_str_equal_location = get_env_equal_location(env_str);
		if (ft_strncmp(env_key, env_str, ft_strlen(env_key)) == 0 && \
							(int)ft_strlen(env_key) == env_str_equal_location)
			return (ft_substr(env_str, env_str_equal_location + 1, \
													ft_strlen(env_str)));
		env_list = env_list->next;
	}
	return (ft_strdup(""));
}

static int	is_env_key_word(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

int	get_env_key_size(char *env_key)
{
	int	i;

	i = 0;
	while (is_env_key_word(env_key[i]))
		++i;
	return (i);
}
