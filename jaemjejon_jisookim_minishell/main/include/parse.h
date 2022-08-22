/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:44:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 21:03:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "var_parse.h"
// paring.c
void	parsing(char *line);

// parse_make_cmd.c
void	make_cmd_list(void);
void	make_redirect_tokens(t_token *cur_token);
void	make_word_token(t_token *cur_token);
t_cmd	*ft_getlstcmd_last(void);
void	parse_add_redirect_token(t_token *token_addr, int io);
void	parse_add_word_token(t_token *token_addr);
void	make_cmd_node(t_token *cur_token);

// parse_make_token.c
void	make_token_list(char *line);

#endif