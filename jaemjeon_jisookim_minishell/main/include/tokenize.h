/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:45:08 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/20 11:54:05 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_addenv(char *key, char *value);
t_envlst	*ft_env_lstlast(t_envlst *lst);
void		ft_free_envlst(t_envlst *lst);

// token_list_adt_1.c
void	ft_token_lstadd_back(t_token **lst, t_token *new);
int		ft_token_lstsize(t_token *lst);
t_token	*ft_addtoken(int type, int redirect_type, char *word_value);
t_token	*ft_token_lstlast(t_token *lst);
void	ft_free_token(t_token *lst);
t_token	*ft_tokendup(t_token *token);