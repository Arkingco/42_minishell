/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/08/27 15:46:03 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"env.h"

char *get_env_value() // char *env_key 지워둠
{
	return (ft_strdup("ls > a"));
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
