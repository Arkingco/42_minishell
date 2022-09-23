/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:26:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 01:54:34 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_cal_output_len(unsigned long dec, int base_len)
{
	int	len;

	if (dec == 0)
		return (1);
	len = 0;
	while (dec)
	{
		dec /= base_len;
		len++;
	}
	return (len);
}

char	*ft_uito_other_base(unsigned int dec, char *base)
{
	char	*output;
	int		base_len;
	int		output_len;
	int		index;

	base_len = ft_strlen(base);
	output_len = ft_cal_output_len(dec, ft_strlen(base));
	output = (char *)malloc(sizeof(char) * (output_len + 1));
	output[output_len] = '\0';
	index = output_len - 1;
	while (index >= 0)
	{
		output[index] = base[dec % base_len];
		dec /= base_len;
		index--;
	}
	return (output);
}

char	*ft_longto_other_base(unsigned long dec, char *base)
{
	char	*output;
	int		base_len;
	int		output_len;
	int		index;

	base_len = ft_strlen(base);
	output_len = ft_cal_output_len(dec, ft_strlen(base));
	output = (char *)malloc(sizeof(char) * (output_len + 1));
	output[output_len] = '\0';
	index = output_len - 1;
	while (index >= 0)
	{
		output[index] = base[dec % base_len];
		dec /= base_len;
		index--;
	}
	return (output);
}
