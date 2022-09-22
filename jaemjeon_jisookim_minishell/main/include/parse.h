/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 14:29:34 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs/t_token.h"
# include "structs/t_cmd.h"

// parse.c
void	combine_redirect_filename(t_token *token_lst);
t_cmd	*token_to_cmd(t_token *token_lst);
void	word_join(t_token **token_lst);
void	quote_remove(t_token **token_lst);
void	word_split(t_token **token_lst);
void	remove_trash_token(t_token **token_lst);

//parse_util_1.c
void	__skip_envkey(char **pointer);
int		__is_to_remove_dollar(t_token *cur_token, char *context);
void	__skip_only_quote_and_letter(char **pointer);
int		is_ifs_word(char *string_value);
int		is_to_word_split(t_token *token);
t_token	*__word_split(t_token *token);
char	*cpy_ifs_string(char **context);

// cmd_adt_1.c
t_cmd	*make_cmd_linkedlst(t_token *token_lst);
t_cmd	*ft_cmd_lst_first(t_cmd *cmd_lst);
#endif
