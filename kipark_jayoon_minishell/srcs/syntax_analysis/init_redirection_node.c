/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:53:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 21:54:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_redir_chunk	*init_redirection_node(char *str_redir, char *str_file_name)
{
	t_redir_chunk	*new;

	new = (t_redir_chunk *)ft_safe_malloc(sizeof(t_redir_chunk));
	new->redir = str_redir;
	new->file_name = str_file_name;
	new->next = NULL;
	return (new);
}
