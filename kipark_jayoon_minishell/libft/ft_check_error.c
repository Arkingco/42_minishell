/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:03 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/31 18:20:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_check_error(t_error e, ssize_t data)
{
	if (e == E_LIBFT && data == 0)
	{
		ft_putstr_fd("Error: libft error\n", 2);
		exit(1);
	}
	else if (e == E_SYSTEM_CALL && data == -1)
	{
		perror("system call");
		exit(1);
	}
	else if (e == E_MALLOC && data == 0)
	{
		perror("malloc");
		exit(1);
	}
}
