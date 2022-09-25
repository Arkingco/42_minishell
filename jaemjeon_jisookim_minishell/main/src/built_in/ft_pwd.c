/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 16:41:15 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_cmd *cmd, t_working_info *info)
{
	char	*cur_pwd;

	(void)&cmd;
	if (info->cur_path != NULL)
		printf("%s\n", info->cur_path);
	else
	{
		process_errno(1, NULL, CUR_PATH_ERR);
		cur_pwd = getcwd(NULL, 0);
		if (cur_pwd != NULL)
		{
			printf("%s\n", cur_pwd);
			free(cur_pwd);
			cur_pwd = 0;
		}
		else
			process_errno(1, NULL, GET_CWD_ERR);
		return (1);
	}
	return (0);
}
