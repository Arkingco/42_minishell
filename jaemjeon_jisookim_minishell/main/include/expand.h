/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:59:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/31 21:27:58 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "token.h"
# include "env.h"

void	expander(t_token **token_lst, t_envlst *env);
void	expand_pidenv(t_token *token);
char	*raise_buffer(char *prev, int raise_size);
void	__skip_envkey(char **pointer);
int	__is_to_remove_dollar(t_token *cur_token, char *context);
char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env);
char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context);
char	*cpy_ifs_string(char **context);
void	__skip_only_quote_and_letter(char **pointer);
void	*cpy_none_expander(char **context);
void	expand_env(t_token *token, t_envlst *env);
void	remove_trash_token(t_token **token_lst);
int	is_ifs_word(char *string_value);
int	is_to_word_split(t_token *token);
t_token	*__word_split(t_token *token);
void	word_split(t_token **token_lst);
void	quote_remove(t_token **token_lst);
void	word_join(t_token **token_lst);

#endif