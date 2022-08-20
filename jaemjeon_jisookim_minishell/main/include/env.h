/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:44:59 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/20 11:54:05 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// env_list_adt_2.c
// t_envlst	*ft_env_lstdup(t_envlst *lst);

t_envlst	*ft_getenv_lst(char *key);
char		*ft_getenv(char *key);
int			ft_delenv(char *key);
void		ft_addenv_str(char *str_envp);

// env_list_adt_3.c
int		ft_has_env(char *key);
void	ft_setenv(char *key, char *value);
char	**ft_envlst_to_envp(void);

// env.c
void	env(void);