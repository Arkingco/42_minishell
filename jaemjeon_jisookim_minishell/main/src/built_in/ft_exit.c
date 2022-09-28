/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:05 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 15:38:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_alnum_string(char *string)
{
	while (*string != '\0')
	{
		if (ft_isdigit(*string) == FALSE)
			return (FALSE);
		string++;
	}
	return (TRUE);
}

int	ft_exit(t_cmd *cmd, t_working_info *info)
{
	char	*arg_string;

	(void)cmd;
	(void)info;
	ft_putendl_fd("exit", 2);
	if (cmd->simple_cmd->next == NULL)
		exit(0);
	if (cmd->simple_cmd->next->next != NULL)
	{
		process_errno(1, "exit", MANY_ARG_ERR);
		return (1);
	}
	else
	{
		arg_string = cmd->simple_cmd->next->string_value;
		if (is_alnum_string(arg_string) == FALSE)
		{
			process_errno(255, "exit", NOT_NUM_ARG_ERR);
			exit(255);
		}
		else
			exit(ft_atoi(arg_string));
	}
	return (0);
}
