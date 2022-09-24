/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:22:00 by kipark            #+#    #+#             */
/*   Updated: 2022/09/24 15:23:00 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_index(char *str, char word)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == word)
			return (i);
		++i;
	}
	return (0);
}
