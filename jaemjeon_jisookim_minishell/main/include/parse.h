/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 19:57:18 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs/t_token.h"
# include "structs/t_cmd.h"

// parse_cmd_lst
t_cmd	*make_cmd_linkedlst(t_token *token_lst);
t_cmd	*ft_cmd_lst_first(t_cmd *cmd_lst);
int		ft_cmdlst_size(t_cmd *cmd);

// parse_free
void	ft_free_cmd(t_cmd *cmd);
void	ft_free_cmdlst(t_cmd *cmd);

// parse_ifs
char	*cpy_ifs_string(char **context);
int		is_ifs_word(char *string_value);

// parse_remove
void	quote_remove(t_token **token_lst);
void	remove_trash_token(t_token **token_lst);

// parse_word
int		is_to_word_split(t_token *token);
void	word_split(t_token **token_lst);

// parse_tools
void	__skip_envkey(char **pointer);
int		__is_to_remove_dollar(t_token *cur_token, char *context);
void	__skip_only_quote_and_letter(char **pointer);
t_token	*__word_split(t_token *token);

//parse_word
void	word_join(t_token **token_lst);
int		is_to_word_split(t_token *token);
void	word_split(t_token **token_lst);

// parse.c
void	combine_redirect_filename(t_token *token_lst);
t_cmd	*token_to_cmd(t_token *token_lst);

#endif
