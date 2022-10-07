/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exceed_max_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:24:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 10:40:44 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libft.h"

void	is_exceed_max_fd(int fd)
{
	if (fd > 250)
	{
		safe_close(fd);
		ft_putendl_fd("Fd exceeds max!", 2);
		exit(1);
	}
}
