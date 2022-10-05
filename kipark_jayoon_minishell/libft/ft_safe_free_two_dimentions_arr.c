/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free_two_dimentions_arr.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:47:14 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/05 21:19:36 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_safe_free_two_dimentions_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	ft_safe_free(arr);
}
