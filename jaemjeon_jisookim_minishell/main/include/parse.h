/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:44:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/20 13:32:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// paring.c
void	parsing(char *line);

// parse_make_cmd.c
void	make_token_list(char *line);
void	make_redirect_tokens(t_token *cur_token);
void	make_word_token(t_token *cur_token);
void	make_cmd_node(t_token *cur_token);
void	make_cmd_list(void);
void	parse_add_redirect_token(t_token *token_addr, int io);
void	parse_add_word_token(t_token *token_addr);
t_cmd	*ft_getlstcmd_last(void);

// parse_token.c
void	parse_add_redirect_token(t_token *token_addr, int io);