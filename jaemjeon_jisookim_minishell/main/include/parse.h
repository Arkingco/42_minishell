/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:44:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 22:30:16 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "var_parse.h"
// paring.c
t_cmd	*parsing(char *line);

// parse_make_cmd.c
t_cmd	*make_cmd_list(t_token *lst_token);
void	ft_make_one_cmd(t_cmd **result, t_token **start_token);
int	ft_input_token_in_cmd(t_cmd *cmd, t_token **token);

// cmd_list_adt_1.c
void	ft_cmd_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_cmd_lstlast(t_cmd *lst);
#endif