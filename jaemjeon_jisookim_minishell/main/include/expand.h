/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:59:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 14:27:44 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "structs/t_token.h"
# include "structs/t_env.h"

// expand.c
void	expander(t_token **token_lst, t_envlst *env);
void	expand_env(t_token *token, t_envlst *env);
char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context);
void	expand_pidenv(t_token *token);
void	*cpy_none_expander(char **context);

// expand_util_1.c
char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env);
char	*raise_buffer(char *prev, int raise_size);


#endif
