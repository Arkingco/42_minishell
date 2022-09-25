/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:55:46 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_home_env(t_cmd *cmd, t_working_info *info, char *togo_path)
{}

int	is_exist_dir(char *dir_path)
{
	DIR	*dp;

	dp = opendir(dir_path);
	if (dp == NULL)
		return (FALSE);
	else
		return (TRUE);
}

int	processing_cd(t_cmd *cmd, t_working_info *info, char *path)
{
	int		ret_chdir;

	ret_chdir = 0;
	if (is_exist_dir(path))
	{
		chdir(path);
		change_info_path(cmd, info, path);
	}
	else
	{
		process_errno(1, NULL, CHANGE_DIR_ERR);
		ret_chdir = 1;
	}
	return (ret_chdir);
}

int	ft_cd(t_cmd *cmd, t_working_info *info)
{
	char	*togo_path;

	if (cmd->simple_cmd->next != NULL)
	{
		togo_path = cmd->simple_cmd->next->string_value;
		if (processing_cd(cmd, info, togo_path) == FAIL)
			return (1);
	}
	else
	{
		if (ft_has_env(info->env, "HOME"))
		{
			togo_path = ft_getenv(info->env, "HOME");
			return (processing_cd(cmd, info, togo_path));
		}
		else
		{
			process_errno(1, NULL, HOME_SET_ERR);
			return (1);
		}
	}
	return (0);
}
