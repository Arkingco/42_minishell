/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:33:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/01 16:09:09 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "lexer.h"

typedef struct s_simple_cmd
{
	char				*str;
	struct s_simple_cmd	*next;
}	t_simple_cmd;

typedef struct s_redir_chunk
{
	char					*redir;
	char					*file_name;
	struct s_redir_chunk	*next;
}	t_redir_chunk;

typedef struct s_redir_iter
{
	t_redir_chunk	*l_input;
	t_redir_chunk	*l_output;
}	t_redir_iter;

typedef struct s_parsing_data_structure
{
	t_simple_cmd					*l_simple_cmd;
	t_redir_iter					*redir_iter;
	struct s_parsing_data_structure	*next;
}	t_parsing_list;

t_parsing_list	*parser(t_token *l_token);
t_parsing_list	*init_parsing_list(void);

#endif
