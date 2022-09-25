/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:15:28 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:22:55 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_cur_path(t_working_info *info)
{
	if (info->cur_path != NULL)
		{
			free(info->cur_path);
			info->cur_path = 0;
		}
}

void	change_info_path(t_cmd *cmd, t_working_info *info, char *path)
{
	char	*tmp_path;

	(void)&cmd;
	tmp_path = getcwd(NULL, 0);
	if (tmp_path != NULL)
	{
		free_cur_path(info);
		info->cur_path = tmp_path;
		if (ft_has_env(info->env, "PWD"))
			ft_setenv(info->env, "OLDPWD", ft_getenv(info->env, "PWD"), TRUE);
		ft_setenv(info->env, "PWD", tmp_path, TRUE);
	}
	else
	{
		tmp_path = ft_strjoin_triple(info->cur_path, "/", path);
		free_cur_path(info);
		info->cur_path = tmp_path;
	}
}
