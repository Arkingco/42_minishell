/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:39:36 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 13:40:00 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

typedef struct s_token
{
	unsigned int	type;
	char			*string_value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_readstate
{
	int				index_word_start;
	unsigned int	state;
}	t_readstate;

#endif
