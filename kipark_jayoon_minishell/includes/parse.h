/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:37:04 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/20 14:32:17 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H


// #define	M_DOUBLE_QUOTE 			"\""
// #define	M_SINGLE_QUOTE 			"\'"
// #define	M_INPUT_REDIR 	"<"
// #define	M_OUTPUT_REDIR 	">"
// #define	M_PIPE 					"|"
// #define	T_HEAR_DOC_REDIR	"<<"
// #define	T_APPEND_REDIR	">>"
// #define	M_NOT_WORD				"NW"

typedef enum e_metacharacter
{
	M_DOUBLE_QUOTE 		= '\"',
	M_SINGLE_QUOTE 		= '\'',
	M_INPUT_REDIR 		= '<',
	M_OUTPUT_REDIR 		= '>',
	M_PIPE 				= '|',
}	t_metacharacter;

typedef enum e_token_type
{
	T_NULL,
	T_WORD,
	T_DOUBLE_QUOTE,
	T_SINGLE_QUOTE,
	T_INPUT_REDIR,
	T_HERE_DOC,
	T_OUTPUT_REDIR,
	T_APPEND_REDIR,
	T_PIPE
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*str;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(char *readline);
void	init_token_dummy_node(t_token *token_head);
void	token_add_list(t_token *token_head, t_token_type token_type, \
															char *token_str);

#endif
