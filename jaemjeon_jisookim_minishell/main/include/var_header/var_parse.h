/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:13:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 22:13:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_PARSE_H
# define VAR_PARSE_H

# include "var_enum_def.h"
# include "var_tokenize.h"

typedef struct s_simple_command
{
	t_token						*cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_redirect
{
	t_token		*redirect_input; // 리다이렉트 종류와 파일 이름이 함께 저장되어있습니다
	t_token		*redirect_output;
	t_token		*unused_token; // 리다이렉트 종류만 저장되어 있기때문에 쓰이지 않습니다.
}	t_redirect;

typedef struct s_cmd
{
	t_simple_command	simple_command;
	t_redirect			redirect;
	struct s_cmd		*next;
}	t_cmd;

#endif
