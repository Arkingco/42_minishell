/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_tokenize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:13:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 22:42:45 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_TOKENIZE_H
# define VAR_TOKENIZE_H

# include "var_enum_def.h"

typedef struct s_token
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_readstatus
{
	unsigned char	quote_flag;
	int				index_quote_start;
	int				index_word_start;

}	t_readstatus;

#endif
