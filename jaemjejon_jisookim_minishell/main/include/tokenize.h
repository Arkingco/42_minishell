/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:45:08 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:41:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "var_tokenize.h"

// tokenizing.c
void	tokenizing(char *line);

// token_list_adt_1.c
void	ft_token_lstadd_back(t_token **lst, t_token *new);
int		ft_token_lstsize(t_token *lst);
t_token	*ft_addtoken(int type, int redirect_type, char *word_value);
t_token	*ft_token_lstlast(t_token *lst);
void	ft_free_token(t_token *lst);
t_token	*ft_tokendup(t_token *token);

// tokenizer_util_1.c
void	reset_readstatus(t_readstatus *readstatus);

#endif