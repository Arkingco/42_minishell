/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_tokenize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:13:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:51:41 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_TOKENIZE_H
# define VAR_TOKENIZE_H

# define DQUOTE 0b00000001
# define SQUOTE 0b00000010
# define QUOTE 0b00000011

typedef struct s_token
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
}	t_token;

typedef struct s_readstatus
{
	unsigned char	quote_flag;
	int				index_quote_start;
	int				index_word_start;

}	t_readstatus;

#endif