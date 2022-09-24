/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:36:49 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 19:54:12 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_double(char **board)
{
	char	**tmp_board;

	tmp_board = board;
	while (*tmp_board != NULL)
	{
		free(*tmp_board);
		tmp_board++;
	}
	free(board);
}
