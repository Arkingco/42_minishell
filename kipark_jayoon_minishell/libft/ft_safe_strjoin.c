/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:38:19 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 16:00:13 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_safe_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		ft_check_error(E_MALLOC, (ssize_t)str);
	return (str);
}