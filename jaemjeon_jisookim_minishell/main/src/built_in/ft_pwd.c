/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 19:59:11 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(t_cmd *cmd, t_working_info *info)
{
	char	*cur_pwd;

	(void)&cmd;
	if (info->cur_path != NULL)
		printf("%s\n", info->cur_path);
	else
	{
		cur_pwd = ft_getcwd(NULL, 0);
		if (cur_pwd != NULL)
		{
			printf("%s\n", cur_pwd);
			free(cur_pwd);
		}
	}
}
