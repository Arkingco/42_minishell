/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_tokenize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:11:40 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/21 19:00:28 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

#ifndef VAR_TOKENIZE_H
# define VAR_TOKENIZE_H

typedef enum e_token	t_token_type;

enum e_token
{
	E_WORD 		= 1,
	E_REDIRECT	= 2,
	E_PIPE		= 3,
	E_NULL		= 4
};

# endif