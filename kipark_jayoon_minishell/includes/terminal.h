/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:14:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 16:56:21 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "lexer.h"

typedef enum e_terminal_type
{
	DEFAULT_TERMINAL,
	HERE_DOC_TERMINAL,
	EXECUTE_TERMINAL
}	t_terminal_type;

void	init_terminal(t_terminal_type t_type);
void	exit_readline_return_null(void);
void	set_terminal_prompt_sigint_not_print(void);
void	set_terminal_prompt_sigint_print(void);

#endif
