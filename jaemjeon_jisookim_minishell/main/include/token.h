/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:46:39 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 14:30:37 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "structs/t_token.h"

// tokenize.c
t_token		*tokenize(char *line);

// split_all_component.c
t_token		*split_all_component(char *line);

// read_token_func.c
t_token		*read_in_quote(char *line, int *index);
t_token		*read_in_redirect(char *line, int *index);
t_token		*read_in_pipe(char *line, int *index);
t_token		*read_in_expander(char *line, int *index);
t_token		*read_in_pureword(char *line, int *index);

// read_token_util_1.c
void		move_index_to_pair_quote(t_token *token, char *line, int *index);
void		move_index_next_to_end_of_word(char *line, int *index);
int			is_leftjoined(char *line, int left_idx);
int			is_rightjoined(char *line, int right_idx);
void		set_flag_joined(t_token *token, char *line, int start_idx, int end_idx);

// token_list_adt_1.c
void		ft_token_lstadd_back(t_token **lst, t_token *new);
int			ft_token_lstsize(t_token *lst);
t_token		*ft_addtoken(t_token **lst, unsigned int type, char *string_value);
void		ft_free_token(t_token *lst);
t_token		*ft_token_lstlast(t_token *lst);
void		ft_free_tokenlst(t_token *lst);

// token_list_adt_2.c
void		ft_deltoken(t_token **lst);
t_token		*ft_token_lst_first(t_token *lst);
t_token		*ft_make_newtoken(unsigned int type, char *string_value);
void		ft_insert_token(t_token *prev_to_insert, t_token *to_insert);
t_token		*ft_strtok_token(unsigned int type, char **string);

#endif
