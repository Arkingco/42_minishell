/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:38:19 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 16:00:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_safe_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_substr(s, start, len);
	if (str == NULL)
		ft_check_error(E_MALLOC, (ssize_t)str);
	return (str);
}
