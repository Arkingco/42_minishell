/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:37:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:05:56 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	parsing(char *line)
{
	make_token_list(line); // 토큰을 여기서 만듭니다.
	make_cmd_list(); // 토큰을 cmd struct에 넣어줍니다.
}
