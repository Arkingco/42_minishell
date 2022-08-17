/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 03:35:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/07 15:06:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"
# define INT_MAX 2147483647

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_env_lstnew(char *key, char *value);
t_envlst	*ft_env_lstlast(t_envlst *lst);
t_envlst	*ft_env_lstdelone(t_envlst *lst, char *key);
t_envlst	*ft_env_lstdup(t_envlst *lst);
void		ft_env_lstclear(t_envlst *lst);
char		*ft_get_env_value(char *key);

#endif
