/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:45:08 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 23:44:40 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "var_tokenize.h"

// tokenizing.c
t_token	*tokenizing(char *line);

// token_list_adt_1.c
void	ft_token_lstadd_back(t_token **lst, t_token *new);
int		ft_token_lstsize(t_token *lst);
t_token	*ft_addtoken(t_token **token, int type, int redirect_type, char *word_value);
t_token	*ft_token_lstlast(t_token *lst);
void	ft_free_token(t_token *lst);
t_token	*ft_tokendup(t_token *token);
void	ft_deltoken(t_token **p_to_del);
void	ft_jointoken_with_next(t_token **p_first_token);
void	ft_jointoken_with_prev(t_token **p_second_token);

// tokenizer_util_1.c
void	reset_readstatus(t_readstatus *readstatus);

#endif
