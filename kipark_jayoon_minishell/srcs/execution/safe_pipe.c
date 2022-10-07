/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:16:54 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 10:32:26 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

void	safe_pipe(int *fd)
{
	int	ret;

	ret = pipe(fd);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
	is_exceed_max_fd(fd[0]);
	is_exceed_max_fd(fd[1]);
}
