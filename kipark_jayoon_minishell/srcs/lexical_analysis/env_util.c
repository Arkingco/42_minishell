/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 18:54:07 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"env.h"
#include"libft.h"
#include <stdio.h>

char *get_env_key(char *str)
{
	int		env_key_size;
	char	*env_key;

	env_key_size = get_env_key_size(str);
	env_key = ft_safe_substr(str, 0, env_key_size);
	return (env_key);
}

char *get_env_value(t_env *env_head, char *env_key)
{
	t_env 	*env_list;

	env_list = env_head->next;
	// if (*env_key == '?') /// 종료상태 코드를 전역 변수로 가지고 온다면 처리 해주면 될 듯
	//	return (error_status);
	while (env_list)
	{
		if (ft_strncmp(env_key, env_list->key, ft_strlen(env_key) + 1) == 0)
			return (ft_safe_strdup(env_list->value));
		env_list = env_list->next;
	}
	return (ft_safe_strdup(""));
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
