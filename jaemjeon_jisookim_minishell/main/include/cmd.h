/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:25:57 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/30 17:02:26 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "token.h"

typedef struct s_cmd
{
	t_token			*simple_cmd;
	t_token			*redirect_input;
	t_token			*redirect_output;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

// cmd_adt_1.c
t_cmd	*ft_cmd_lst_first(t_cmd *cmd_lst);
t_cmd	*make_cmd_linkedlst(t_token *token_lst);
void	ft_free_cmd(t_cmd *cmd);
void	ft_free_cmdlst(t_cmd *cmd);

#endif
