/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 10:41:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_unset(t_cmd *cmd, t_working_info *info)
{
	t_token	*to_unset_token;
	int errno_res;

	to_unset_token = cmd->simple_cmd->next;
	while (to_unset_token != NULL)
	{
		if (ft_delenv(&info->env,to_unset_token->string_value) == FALSE)
		{
			errno_res = errno;
			ft_putendl_fd(strerror(errno_res), 2);
			return(errno_res);
		}
		to_unset_token = to_unset_token->next;
	}
	return (0);
}
