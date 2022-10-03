/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_syntax_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:42:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 14:49:09 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

void	*print_syntax_error(t_token *l_token)
{
	if (!l_token)
		return (NULL);
	printf("minishell: syntax error near unexpected token\n");
	return (NULL);
}
