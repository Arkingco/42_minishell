/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:52:07 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/18 01:44:11 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_error_exit(int exit_status, char *message)
{
	ft_putendl_fd(message, 2);
	exit(exit_status);
}

void	exec_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putendl_fd(" : ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(errno);
}
