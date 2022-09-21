/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simple_cmd_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:13:14 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/19 20:15:31 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

void	*init_simple_cmd_node(char *str)
{
	t_simple_cmd	*new;

	new = (t_simple_cmd *)ft_safe_malloc(sizeof(t_simple_cmd));
	new->str = str;
	new->next = NULL;
	return (new);
}
