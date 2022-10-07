/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_system_call_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:07:40 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 17:03:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_system_call_error(int data, char *file_name)
{
	if (data == -1)
	{
		ft_multi_putendl_fd("minishell: ", file_name, \
			": No such file or directory", 2);
		return (1);
	}
	return (0);
}
