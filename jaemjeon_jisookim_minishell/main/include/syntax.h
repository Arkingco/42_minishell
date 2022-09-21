/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:42:47 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 15:07:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "token.h"

int		check_token_type(t_token *token);
int		check_syntax_token(t_token *tok, int *tok_types);
int		check_front_and_back_tokens(int front, int back);
int		count_token(t_token *token);
void	check_syntax(t_token *lst_token);

#endif