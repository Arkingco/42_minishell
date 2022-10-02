/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:22:26 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 16:18:22 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"env.h"
#include"libft.h"
#include"exit_status.h"
#include <stdio.h>

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
	if (*env_key == '?' || ft_isdigit(*env_key))
		return (1);
	while (is_env_key_word(env_key[i]))
		++i;
	return (i);
}
