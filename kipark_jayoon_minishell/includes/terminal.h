/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:14:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/02 11:38:21 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

#include "lexer.h"

void    init_terminal(void);
void	exit_readline_return_null(void);
void	free_main_line_and_token(char *line, t_token *token);

#endif
