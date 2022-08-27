/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:37:04 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/27 15:41:30 by kipark           ###   ########seoul.kr  */
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

#define NULL_CHAR '\0'

typedef enum e_metacharacter
{
	M_DOUBLE_QUOTE 		= '\"',
	M_SINGLE_QUOTE 		= '\'',
	M_INPUT_REDIR 		= '<',
	M_OUTPUT_REDIR 		= '>',
	M_PIPE 				= '|',
	M_DOLLAR_EXPAND		= '$',
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

// parse.c
t_token	*tokenize(char *str);
void	word_token_add(t_token *token_head, t_token_type t_type, \
															char *expand_str);
int	get_quote_type_return_index(char *rl, int i, \
												t_token_type this_token_type);
// token*.c
void	init_token_dummy_node(t_token *token_head);
void	token_add(t_token *token_head, t_token_type token_type, \
															char *token_str);
void	print_token_list(t_token *token_head);
void	token_free(t_token *token);

// token_expand*.c
char	*expand_this_word_token(char *expand_str);

// parse_util*.c
int		pass_ifs(char *rl, int i);
int		ft_isifs(int c);
int		is_metachar_not_include_quote(char c);
int		check_readline_able_parse(char *rl);
void	pass_sigle_quote(char *str, int *i);

// token_quote_*.c
void	quote_rmove(t_token *token_head);


#endif
