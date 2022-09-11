/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:44:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/12 03:11:38 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_envlst
{
	char			*key;
	char			*value;
	int				has_value;
	struct s_envlst	*next;
	struct s_envlst	*prev;
}	t_envlst;


// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_addenv(t_envlst **env, char *key, char *value, int has_value);
void		ft_free_envlst(t_envlst *lst);
t_envlst	*ft_env_lstlast(t_envlst *lst);

// env_list_adt_2.c
t_envlst	*ft_getenv_lst(t_envlst *env, char *key);
char		*ft_getenv(t_envlst *env, char *key);
int			ft_delenv(t_envlst **env, char *key);
void		ft_addenv_str(t_envlst **env, char *str_envp);
t_envlst	*ft_env_lst_first(t_envlst *lst);

// env_list_adt_3.c
int			ft_has_env(t_envlst *env, char *key);
void		ft_setenv(t_envlst *env, char *key, char *value, int has_value);
char		**ft_envlst_to_envp(t_envlst *env);
char		*ft_envlst_to_string(t_envlst *lst);

#endif