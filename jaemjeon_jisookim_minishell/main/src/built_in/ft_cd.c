/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 11:15:13 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_info_path(t_cmd *cmd, t_working_info *info, char *path)
{
	char	*tmp_path;

	(void)&cmd;
	tmp_path = ft_getcwd(NULL, 0);
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
	char	*error_message;

	if (is_exist_dir(path))
	{
		ret_chdir = ft_chdir(path);
		change_info_path(cmd, info, path);
	}
	else
	{
		error_message = ft_strjoin("minishell: cd: ", path);
		perror(error_message);
		free(error_message);
		error_message = 0;
		ret_chdir = FAIL;
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
			processing_cd(cmd, info, togo_path);
		}
		else
		{
			ft_putendl_fd("minishell: cd: HOME not set", 2);
			return (errno);
		}
	}
	return (0);
}
