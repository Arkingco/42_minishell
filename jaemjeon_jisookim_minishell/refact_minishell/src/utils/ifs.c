/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:00:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 04:54:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_ifs(const char *letter)
{
	return ((*letter == ' ') || (*letter == '\t') || (*letter == '\n'));
}

int	ft_skip_ifs(char **string_pointer)
{
	int	skip_count;

	skip_count = 0;
	while (ft_is_ifs(*string_pointer))
	{
		(*string_pointer)++;
		skip_count++;
	}
	return (skip_count);
}