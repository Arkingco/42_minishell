/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:46:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 14:27:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_parsing_list	*init_parsing_list(void)
{
	t_parsing_list	*l_parsing;

	l_parsing = (t_parsing_list *)ft_safe_malloc(sizeof(t_parsing_list));
	l_parsing->l_simple_cmd = NULL;
	l_parsing->next = NULL;
	l_parsing->redir_iter = NULL;
	return (l_parsing);
}
