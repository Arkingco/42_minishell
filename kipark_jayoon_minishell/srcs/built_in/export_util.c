/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 17:15:08 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "libft.h"
#include "built.h"
#include "env.h"

int	get_equal_location(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		++i;
	if (str[i] == '=')
		return (i);
	else
		return (0);
}