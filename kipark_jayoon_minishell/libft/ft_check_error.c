/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:03 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 20:48:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_check_error(t_error e, ssize_t data)
{
	ssize_t	ret;

	if (e == E_LIBFT && data == 0)
	{
		ret = ft_putstr_fd("Error: libft error\n", 2);
		ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
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
