/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:05 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 16:57:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit(t_exec *exec)
{
	return (0);
}

void	ft_exit_if(t_exec *exec, int condition)
{
	if (condition)
		ft_exit(exec);
	return ;
}
