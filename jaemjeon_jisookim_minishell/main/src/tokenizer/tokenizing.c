/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:39:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:54:45 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	tokenizing(char *line)
{
	t_readstatus	readstatus;
	int				index;

	reset_readstatus(&readstatus);
	index = 0;
}
