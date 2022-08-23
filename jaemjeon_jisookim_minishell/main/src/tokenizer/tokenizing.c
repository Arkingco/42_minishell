/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:39:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:52:12 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tokenizing(char *line)
{
	t_readstatus	readstatus;
	int				index;

	reset_readstatus(&readstatus);
	index = 0;
	// 토큰을 동적할당하여 그 리스트를 반환해야 합니다.
}
