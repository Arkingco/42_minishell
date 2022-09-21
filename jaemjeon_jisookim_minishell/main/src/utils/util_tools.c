/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:48:26 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 11:04:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_double_free(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	*safe_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = 0;
	ret = ft_calloc(count, size);
	if (!ret)
		exit(1);
	return (ret);
}

void	set_sigtermset(int mode)
{
	set_termios(mode);
	set_signal(mode);
}