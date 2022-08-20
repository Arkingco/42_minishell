/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:37:04 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/20 11:12:58 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum e_metacharacter
{
	M_DOUBLE_QUOTE 		= '\"',
	M_SINGLE_QUOTE 		= '\'',
	M_INPUT_REDIRECTION 	= '<',
	M_OUTPUT_REDIRECTION 	= '>',
	M_PIPE 				= '|',
	M_NOT
}	t_metacharacter;

typedef enum e_token_type
{
	T_NULL,
	T_WORD,
	T_DOUBLE_QUOTE,
	T_SINGLE_QUOTE,
	T_INPUT_REDIRECTION,
	T_HERE_DOC_REDIRECTION,
	T_OUTPUT_REDIRECTION,
	T_APPEND_REDIRECTION,
	T_PIPE
}	t_token_type;

typedef struct s_token
{
	char			*type;
	char			*str;
	struct s_token	*next;
}	t_token;

void	*tokenize(char *readline);

#endif
