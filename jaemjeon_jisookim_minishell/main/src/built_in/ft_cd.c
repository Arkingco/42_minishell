/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:43:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/20 02:58:39 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_info_path(t_cmd *cmd, t_working_info *info, char *path)
{
	char	*tmp_path;

	tmp_path = ft_getcwd(NULL, 0);
	if (tmp_path != NULL)
	{
		if (info->cur_path != NULL)
			free(info->cur_path);
		info->cur_path = tmp_path;
	}
	else
	{
		tmp_path = ft_strjoin_triple(info->cur_path, "/", path);
		if (info->cur_path != NULL)
			free(info->cur_path);
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
		error_message = ft_strjoin("cd : ", path);
		perror(error_message);
		free(error_message);
		ret_chdir = FAIL;
	}
	return (ret_chdir);
}

void	ft_cd(t_cmd *cmd, t_working_info *info)
{
	int		ret_chdir;
	char	*error_message;
	char	*togo_path;

	if (cmd->simple_cmd->next != NULL)
	{
		togo_path = cmd->simple_cmd->next->string_value;
		processing_cd(cmd, info, togo_path);
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
			// errno를 세팅해줘야함
			ft_putendl_fd("cd : HOME not set", 2);
		}
	}
}
