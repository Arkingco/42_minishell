/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:37:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 23:54:45 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parsing(char *line)
{
	t_token	*lst_token;
	t_cmd	*lst_cmd;

	lst_token = tokenizing(line); // 토큰을 여기서 만듭니다.
	lst_cmd = make_cmd_list(lst_token); // 토큰을 cmd struct에 넣어줍니다.
	lst_cmd++;
	lst_cmd = 0;
	return 0;
}
