/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:45:08 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 19:37:46 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "./variables/var_base_struct.h"

// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new_lst);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_addenv(char *key, char *value);
t_envlst	*ft_env_lstlast(t_envlst *lst);
void		ft_free_envlst(t_envlst *lst);
t_token		*ft_addtoken(int type, int redirect_type, char *word_value);
t_token		*ft_token_lstlast(t_token *lst);
void		ft_free_token(t_token *lst);
t_token		*ft_tokendup(t_token *token);

// tokenizing.c
void		make_token_list(char *line);

#endif