/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:18:33 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/28 14:18:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	safe_close(int fd)
{
	int	ret;

	ret = close(fd);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)fd);
}
