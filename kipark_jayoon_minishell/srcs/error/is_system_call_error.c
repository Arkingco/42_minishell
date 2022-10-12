/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_system_call_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:07:40 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/10 15:36:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_system_call_error(int data, char *file_name)
{
	if (data == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(file_name);
		return (1);
	}
	return (0);
}
