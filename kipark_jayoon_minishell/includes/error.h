/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:44:29 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 17:02:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "lexer.h"

void	*print_syntax_error(t_token *l_token);
void	*print_quote_error(void);
void	is_exceed_max_fd(int fd);
int		is_system_call_error(int data, char *file_name);

#endif
