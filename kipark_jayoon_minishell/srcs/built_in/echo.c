/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:59 by kipark            #+#    #+#             */
/*   Updated: 2022/10/07 18:20:17 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"parser.h"
#include"libft.h"

static int	return_new_line(int exit_status)
{
	ft_putstr_fd("\n", 1);
	return (exit_status);
}

static int	is_only_echo_option(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		++i;
	}
	return (1);
}

static int	is_option(t_simple_cmd *simple_cmd)
{
	if (simple_cmd->str[0] != '-')
		return (0);
	if (is_only_echo_option(&simple_cmd->str[1], 'n'))
		return (1);
	return (0);
}

int	built_in_echo(t_simple_cmd *simple_cmd)
{
	int	echo_n_option;
	int	echo_exit_status;

	echo_exit_status = 0;
	echo_n_option = 1;
	if (simple_cmd->next == NULL)
		return (echo_exit_status = return_new_line(0));
	simple_cmd = simple_cmd->next;
	if (is_option(simple_cmd))
	{
		echo_n_option = 0;
		simple_cmd = simple_cmd->next;
	}
	while (simple_cmd)
	{
		ft_putstr_fd(simple_cmd->str, 1);
		if (simple_cmd->next != NULL)
			ft_putstr_fd(" ", 1);
		simple_cmd = simple_cmd->next;
	}
	if (echo_n_option)
		ft_putstr_fd("\n", 1);
	return (echo_exit_status = 0);
}
