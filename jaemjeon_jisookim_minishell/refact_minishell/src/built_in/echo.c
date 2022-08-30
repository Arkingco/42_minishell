/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:21:09 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/28 17:37:35 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_echo_option(char *input);

int	echo(char **inputs)
{
	int	flag;
	int	i;

	i = 0;
	while (inputs[i])
	{
		flag = is_echo_option(inputs[i]);
		printf("%s", inputs[i]);
		if (!flag)
		{
			printf("\n");
			break ;
		}
		i++;
	}
	return (0);
}

int	is_echo_option(char *input)
{
	int	i;

	i = 1;
	if (input[0] != '-')
		return (0);
	while (input[i])
	{
		if (input[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}