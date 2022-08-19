/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 04:02:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/14 16:25:11 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(ERROR);
}

void	ft_free(void **p_pointer)
{
	free(*p_pointer);
	*p_pointer = NULL;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	output = malloc(count * size);
	
}