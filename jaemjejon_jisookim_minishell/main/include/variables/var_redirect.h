/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_redirect.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:12:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/21 18:59:47 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_REDIRECT_H
 #define VAR_REDIRECT_H

typedef enum e_redirect	t_redirect_type;

enum e_redirect
{
	E_REDI_R 	= 1,	// >
	E_REDI_L	= 2,	// >>
	E_REDI_RR	= 3,	// <
	E_REDI_LL	= 4		// <<
};

typedef struct s_token // to do : value 초기화, redirect_type = 0
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
}	t_token;

typedef struct s_simple_command
{
	t_token						cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_redirect
{
	t_token		*redirect_input[2]; // [0] -> REDIRECT_TOKEN [1] -> FILENAME_TOKEN
	t_token		*redirect_output[2];
}	t_redirect;

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

#endif