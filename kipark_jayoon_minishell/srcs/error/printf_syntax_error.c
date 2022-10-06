/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_syntax_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:42:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/06 11:18:49 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "libft.h"

void	*print_syntax_error(t_token *l_token)
{
	if (!l_token)
		return (NULL);
	ft_putendl_fd("minishell: syntax error near unexpected token", 2);
	return (NULL);
}
