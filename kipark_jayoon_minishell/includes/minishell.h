/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:13:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 10:59:34 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "parser.h"

enum e_exit_status_code
{
	MINISHELL_EXIT_SUCCESS,
	MINISHELL_EXIT_FAIL
};

void	exit_readline_return_null(void);
void	free_all(char *line, t_token *token, t_parsing_list *l_parsing);

#endif
