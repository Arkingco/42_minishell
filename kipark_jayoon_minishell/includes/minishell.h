/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:13:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/02 16:09:06 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "parser.h"

enum e_exit_status_code
{
	SUCCESS,
	FAIL
};

void	exit_readline_return_null(void);
void	free_all(char *line, t_token *token, t_parsing_list *l_parsing);

#endif
