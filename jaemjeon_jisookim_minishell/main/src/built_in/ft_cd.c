/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 17:47:47 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_info_path(t_cmd *cmd, t_working_info *info, char *path)
{
	char	*tmp_path;

	(void)&cmd;
	tmp_path = getcwd(NULL, 0);
	if (tmp_path != NULL)
	{
		if (info->cur_path != NULL)
		{
			free(info->cur_path);
			info->cur_path = 0;
		}
		info->cur_path = tmp_path;
		if (ft_has_env(info->env, "PWD"))
			ft_setenv(info->env, "OLDPWD", ft_getenv(info->env, "PWD"), TRUE);
		ft_setenv(info->env, "PWD", tmp_path, TRUE);
	}
	else
	{
		tmp_path = ft_strjoin_triple(info->cur_path, "/", path);
		if (info->cur_path != NULL)
		{
			free(info->cur_path);
			info->cur_path = 0;
		}
		info->cur_path = tmp_path;
	}
}

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
