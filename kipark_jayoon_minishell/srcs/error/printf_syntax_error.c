/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_syntax_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:42:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 19:10:26 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_status.h"
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "libft.h"
#include "parser.h"

void	*print_syntax_error(void)
{
	g_exit_status = 258;
	ft_putendl_fd("minishell: syntax error near unexpected token", 2);
	return (NULL);
}

void	*print_quote_error(void)
{
	g_exit_status = 1;
	ft_putendl_fd("minishell: quote not ended", 2);
	return (NULL);
}
