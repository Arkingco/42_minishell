/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:44:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 17:35:29 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "structs/t_env.h"

// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_addenv(t_envlst **env, char *key, char *value, int has_value);
void		ft_free_envlst(t_envlst *lst);
t_envlst	*ft_env_lstlast(t_envlst *lst);

// env_list_adt_2.c
int			ft_delenv(t_envlst **env, char *key);
void		ft_addenv_str(t_envlst **env, char *str_envp);
t_envlst	*ft_env_lst_first(t_envlst *lst);

// env_list_adt_3.c
char		*ft_envlst_to_string(t_envlst *lst);
char		**ft_envlst_to_envp(t_envlst *env);
char		*ft_get_value_in_string(char *string);
char		*ft_get_key_in_string(char *string);

// env_list_adt_4.c
int			ft_has_env(t_envlst *env, char *key);
void		ft_setenv(t_envlst *env, char *key, char *value, int has_value);
t_envlst	*ft_getenv_lst(t_envlst *env, char *key);
char		*ft_getenv(t_envlst *env, char *key);
t_envlst	*get_env_new_head(t_envlst *env);

#endif
