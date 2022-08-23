/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:46:39 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 06:33:39 by jaemjeon         ###   ########.fr       */
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

typedef struct s_readstate
{
	int				index_word_start;
	unsigned int	state;
}	t_readstate;

// tokenize.c
t_token		*tokenize(char *line);

// split_all_component.c
t_token	*split_all_component(char *line);

// readstate_util.c
void	ft_reset_readstate(t_readstate *readstate);

// token_list_adt_1.c
void		ft_token_lstadd_back(t_token **lst, t_token *new);
int			ft_token_lstsize(t_token *lst);
t_token		*ft_addtoken(t_token **lst, unsigned int type, char *string_value);
void		ft_free_tokenlst(t_token *lst);
t_token		*ft_token_lstlast(t_token *lst);

// token_list_adt_2.c
void		ft_deltoken(t_token **lst);
t_token		*ft_token_lst_first(t_token *lst);

#endif
