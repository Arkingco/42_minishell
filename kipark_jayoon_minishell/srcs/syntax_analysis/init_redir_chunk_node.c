/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir_chunk_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:53:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 21:43:44 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

t_redir_chunk	*init_redir_chunk_node(t_token_type type, char *str_file_name)
{
	t_redir_chunk	*new;

	new = (t_redir_chunk *)ft_safe_malloc(sizeof(t_redir_chunk));
	new->type = type;
	new->file_name = str_file_name;
	new->next = NULL;
	return (new);
}
