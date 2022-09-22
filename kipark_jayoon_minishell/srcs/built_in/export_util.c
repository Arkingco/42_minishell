/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/21 01:08:42 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "libft.h"
#include "built.h"
#include "env.h"

int	get_equl_location(char *str)
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