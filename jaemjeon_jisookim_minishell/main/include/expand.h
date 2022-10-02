/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:59:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 16:23:32 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "structs/t_token.h"
# include "structs/t_env.h"

// expand_env.c
void	expand_env(t_token *token, t_envlst *env);
char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context);

// expand_pid_env.c
void	expand_pidenv(t_token *token);
void	*cpy_none_expander(char **context);

// expand_tools.c
char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env);
char	*raise_buffer(char *prev, int raise_size);

// expand.c
int		is_heredoc_delimiter_token(t_token *token);
void	expander(t_token **token_lst, t_envlst *env);

#endif
