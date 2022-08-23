/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:46:39 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 03:30:19 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	unsigned int	type;
	char			*string_value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

// token_list_adt_1.c
void		ft_token_lstadd_back(t_token **lst, t_token *new);
int			ft_token_lstsize(t_token *lst);
t_token		*ft_addtoken(t_token *lst, unsigned int type, char *string_value);
void		ft_free_tokenlst(t_token *lst);
t_token		*ft_token_lstlast(t_token *lst);

// token_list_adt_2.c
void		ft_deltoken(t_token **lst);
t_token		*ft_token_lst_first(t_token *lst);

#endif
