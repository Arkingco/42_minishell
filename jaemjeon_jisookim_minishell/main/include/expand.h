/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:59:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/04 22:49:22 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "token.h"
# include "env.h"

void	expander(t_token **token_lst, t_envlst *env);
void	remove_trash_token(t_token **lst_token);
void	quote_remove(t_token **lst_token);
void	word_split(t_token **lst_token);
void	word_join(t_token **lst_token);

#endif