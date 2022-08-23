/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:36:13 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:52:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_readstatus(t_readstatus *readstatus)
{
	readstatus->index_quote_start = -1;
	readstatus->index_word_start = -1;
	readstatus->quote_flag = 0;
}