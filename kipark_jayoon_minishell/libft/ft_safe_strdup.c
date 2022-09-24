/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:38:17 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 16:00:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_safe_strdup(const char *s1)
{
	char	*str;

	str = ft_strdup(s1);
	if (str == NULL)
		ft_check_error(E_MALLOC, (ssize_t)str);
	return (str);
}
