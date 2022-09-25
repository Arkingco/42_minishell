/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:44:49 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/25 16:47:59 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	ft_check_error(E_SYSTEM_CALL, (ssize_t)pid);
	return (pid);
}
