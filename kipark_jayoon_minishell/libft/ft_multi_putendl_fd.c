/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_putendl_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:12:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/25 18:38:22 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_multi_putendl_fd(char *s1, char *s2, char *s3, int fd)
{
	if (!s1 || !s2 || !s3)
		return ;
	if (write(fd, s1, ft_strlen(s1)) < 0)
		ft_check_error(E_LIBFT, 0);
	if (write(fd, s2, ft_strlen(s2)) < 0)
		ft_check_error(E_LIBFT, 0);
	if (write(fd, s3, ft_strlen(s3)) < 0)
		ft_check_error(E_LIBFT, 0);
	if (write(fd, "\n", 1) < 0)
		ft_check_error(E_LIBFT, 0);
	return ;
}
