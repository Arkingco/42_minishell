/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_enum_def.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:20:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 15:21:38 by jaemjeon         ###   ########.fr       */
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

enum	e_token
{
	E_WORD = 0,
	E_REDIRECT,
	E_PIPE,
	E_NULL
};

enum	e_redirect
{
	E_REDI_R = 0,
	E_REDI_L,
	E_REDI_RR,
	E_REDI_LL
};

#endif