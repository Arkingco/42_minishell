/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_syntax_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:42:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 17:47:47 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "libft.h"
#include "exit_status.h"

void	*print_syntax_error(t_token *l_token)
{
	if (!l_token)
		return (NULL);
	g_exit_status = 258;
	ft_putendl_fd("minishell: syntax error near unexpected token", 2);
	return (NULL);
}

void	*print_quote_error()
{
	g_exit_status = 1;
	ft_putendl_fd("minishell: quote not ended", 2);
	return (NULL);
}