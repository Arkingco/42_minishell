/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/14 05:05:06 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_info_path(t_cmd *cmd, t_working_info *info)
{
	char	*tmp_path;
	DIR		*dp;
	char	*to_go_path;

	to_go_path = cmd->simple_cmd->next->string_value;
	if (info->cur_path != NULL)
		free(info->cur_path);
	dp = opendir(to_go_path);
	if (dp == NULL)
	{
		tmp_path = ft_strjoin_triple(info->cur_path, "/", to_go_path);
		info->cur_path = tmp_path;
	}
	else
	{
		closedir(dp);
		if (info->cur_path != NULL)
			free(info->cur_path);
		info->cur_path = ft_getcwd(NULL, 0);
	}
}

void	ft_cd(t_cmd *cmd, t_working_info *info)
{
	int	ret_chdir;

	ret_chdir = ft_chdir(cmd->simple_cmd->next->string_value);
	change_info_path(cmd, info);
}
