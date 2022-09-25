/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 11:44:39 by jisookim         ###   ########.fr       */
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
		cur_pwd = ft_getcwd(NULL, 0);
		if (cur_pwd != NULL)
		{
			printf("%s\n", cur_pwd);
			free(cur_pwd);
			cur_pwd = 0;
		}
		else
		{
			ft_putstr_fd("minishell: annot access directories:", 2);
			ft_putstr_fd("No such file or directory\n", 2);
		}
	}
	return (0);
}
