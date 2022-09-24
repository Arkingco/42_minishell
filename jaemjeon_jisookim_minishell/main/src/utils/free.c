/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:36:49 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 10:37:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_double(char **board)
{
	char	**tmp_board;
	char	*to_free;

	tmp_board = board;
	while (*tmp_board != NULL)
	{
		free(*tmp_board);
		tmp_board++;
	}
	free(board);
}
