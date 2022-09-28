/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:36:49 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:33:11 by jisookim         ###   ########.fr       */
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
		*tmp_board = 0;
		tmp_board++;
	}
	free(board);
	board = 0;
}

void	free_two_strings(char *s1, char *s2)
{
	free(s1);
	s1 = 0;
	free(s2);
	s2 = 0;
}
