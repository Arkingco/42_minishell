/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:19:12 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/28 14:19:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	safe_dup2(int from, int to)
{
	int	ret;

	ret = dup2(from, to);
	ft_check_error(E_SYSTEM_CALL, (ssize_t)ret);
}
