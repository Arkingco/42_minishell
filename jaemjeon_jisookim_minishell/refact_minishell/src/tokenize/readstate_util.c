/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readstate_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 06:00:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 06:02:15 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset_readstate(t_readstate *readstate)
{
	readstate->index_word_start = -1;
	readstate->quote_state = FALSE;
}