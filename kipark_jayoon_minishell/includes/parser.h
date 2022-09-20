/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:33:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/20 21:54:41 by jayoon           ###   ########.fr       */
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

/* parser */
t_parsing_list	*parser(t_token *l_token);
void			check_syntax_and_set_parsing_list(t_token *l_token,
				t_parsing_list *l_parsing);

/* init linked list node */
t_parsing_list	*init_parsing_list(void);
void			*init_simple_cmd_node(char *str);
t_redir_chunk	*init_redirection_node(char *str_redir, char *str_file_name);

/* add node at end of linked list */
void			add_simple_cmd_node(t_simple_cmd **head, t_simple_cmd *node);
void			add_parsing_list_node(t_parsing_list *l_parsing,
					t_parsing_list *node);
void			add_redir_chunk_node(t_redir_chunk **head, t_redir_chunk *node);

/* util */
int				is_word(t_token_type type);
int				is_redirection(t_token_type type);

/* extern util */
void			free_parsing_list(t_parsing_list *l_parsing);

#endif
