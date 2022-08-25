/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:00:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/25 14:54:37 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_ifs(const char *letter)
{
	return ((*letter == ' ') || (*letter == '\t') || (*letter == '\n'));
}

int	ft_skip_ifs1(char **string_pointer)
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

void	ft_skip_ifs2(char *line, int *index)
{
	while (ft_is_ifs(&line[*index]))
		(*index)++;
}
