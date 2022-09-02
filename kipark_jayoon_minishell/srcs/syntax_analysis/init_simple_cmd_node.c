/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:13:14 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/02 16:21:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

void	*init_simple_cmd_node(char *str)
{
	t_simple_cmd	*node;

	node = ft_safe_malloc(sizeof(t_simple_cmd));
	node->str = str;
	node->next = NULL;
	return (node);
}
