/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/29 22:51:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "token.h"

// parse.c
void	combine_redirect_filename(t_token *token_lst);
t_cmd	*token_to_cmd(t_token *token_lst);

// cmd_adt_1.c
t_cmd	*make_cmd_linkedlst(t_token *token_lst);
t_cmd	*ft_cmd_lst_first(t_cmd *cmd_lst);
#endif
