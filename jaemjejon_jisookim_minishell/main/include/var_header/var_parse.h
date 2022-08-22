/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:13:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 18:42:00 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_PARSE_H
# define VAR_PARSE_H

#include "var_tokenize.h"

typedef struct s_simple_command
{
	t_token						*cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_redirect
{
	t_token		*redirect_input[2]; // [0] -> REDIRECT_TOKEN [1] -> FILENAME_TOKEN
	t_token		*redirect_output[2];
}	t_redirect;

typedef struct s_cmd
{
	t_simple_command	simple_command;
	t_redirect			redirect;
	struct s_cmd		*next;
}	t_cmd;

#endif