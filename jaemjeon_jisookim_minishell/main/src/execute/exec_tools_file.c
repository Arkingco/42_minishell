/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:20:36 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/10 20:45:30 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_open(const char *filename, int flags)
{
	int	open_return;
	open_return = open(filename, flags);
	if (open_return == -1)
	{
		ft_putstr_fd("ERROR : open() function error! \n", 2);
		exit(1);
	}
	return (open_return);
}

int	ft_close(int fd)
{
	int	close_return;
	close_return = close(fd);
	if (close_return != 0)
	{
		ft_putstr_fd("ERROR : close() function error! \n", 2);
		exit(1);
	}
	return (close_return);
}
