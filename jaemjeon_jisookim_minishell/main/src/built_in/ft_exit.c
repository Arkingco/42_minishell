/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:05 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/15 17:01:44 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_alnum_string(char *string)
{
	while (*string != '\0')
	{
		if (ft_isalnum(*string) == FALSE)
			return (FALSE);
		string++;
	}
	return (TRUE);
}

static void	print_error_message(char *arg_string)
{
	char	*result_message;
	char	*tmp_string;

	tmp_string = ft_strjoin_triple("exit: ", arg_string, ": ");
	result_message = ft_strjoin(tmp_string, "numeric argument required");
	free(tmp_string);
	ft_putendl_fd(result_message, 2);
}

void	ft_exit(t_cmd *cmd, t_working_info *info)
{
	char	*arg_string;

	ft_putendl_fd("exit", 2);
	if (cmd->simple_cmd->next == NULL)
		exit(0);
	if (cmd->simple_cmd->next->next != NULL)
	{
		// errno를 1로 세팅해야함
		ft_putendl_fd("exit: too many arguments", 2);
	}
	else
	{
		arg_string = cmd->simple_cmd->next->string_value;
		if (is_alnum_string(arg_string) == FALSE)
		{
			print_error_message(arg_string);
			exit(255);
		}
		else
			exit(ft_atoi(arg_string));
	}
}
