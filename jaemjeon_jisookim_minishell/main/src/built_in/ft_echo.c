/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:01 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 15:08:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_n_option(t_cmd *cmd)
{
	char	*suspect_string;

	suspect_string = cmd->simple_cmd->next->string_value;
	if (ft_strncmp(suspect_string, "-n", 3) == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	printing_tokens(t_token *to_print_tokenlst, int n_option_flag)
{
	int	first;

	first = 1;
	while (to_print_tokenlst != NULL)
	{
		if (!first)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(to_print_tokenlst->string_value, 1);
		to_print_tokenlst = to_print_tokenlst->next;
		first = 0;
	}
	if (n_option_flag == FALSE)
		ft_putendl_fd("", 1);
}

int	ft_echo(t_cmd *cmd, t_working_info *info)
{
	int		n_option_flag;
	t_token	*cur_token;

	(void)info;
	cur_token = cmd->simple_cmd->next;
	if (cur_token == NULL)
	{
		ft_putendl_fd("", 1);
		return (0);
	}
	n_option_flag = has_n_option(cmd);
	if (n_option_flag == TRUE)
		cur_token = cur_token->next;
	printing_tokens(cur_token, n_option_flag);
	return (0);
}
