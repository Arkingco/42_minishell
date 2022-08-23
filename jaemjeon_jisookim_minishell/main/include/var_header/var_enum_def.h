/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_enum_def.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:20:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 01:25:34 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_ENUM_DEF_H
# define VAR_ENUM_DEF_H

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define GET 0
# define SET 1

# define INPUT 0
# define OUTPUT 1

# define DQUOTE			0b00000001
# define SQUOTE			0b00000010
# define QUOTE			0b00000011
# define LINKED_STR		0b00000100
# define PIPE			0b00001000
# define REDIR_OVERW	0b00010000
# define REDIR_APPEND	0b00100000
# define REDIR_INFILE	0b01000000
# define REDIR_HERED	0b10000000
# define REDIR			0b11110000
# define REDIR_INPUT	0b11000000
# define REDIR_OUTPUT	0b00110000

typedef enum e_token
{
	E_WORD = 0,
	E_REDIRECT,
	E_PIPE,
	E_NULL
}	t_;

enum	e_redirect
{
	E_REDI_R = 0,
	E_REDI_L,
	E_REDI_RR,
	E_REDI_LL
};

#endif
