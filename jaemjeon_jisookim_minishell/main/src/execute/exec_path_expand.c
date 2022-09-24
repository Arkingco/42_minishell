/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:37:45 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 13:52:35 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	expand_homepath(char **cmd_string, t_working_info *info)
// {
// 	char	*new_cmd_string;
// 	char	*homepath;

// 	homepath = ft_getenv(info->env, "HOME");
// 	if (homepath == NULL)
// 		return ;
// 	if (**cmd_string == '~')
// 	{
// 		new_cmd_string = ft_strjoin(homepath, *cmd_string + 1);
// 		free(*cmd_string);
// 		*cmd_string = new_cmd_string;
// 	}
// }

// int	expand_homepath_and_check_is_there(t_cmd *cmd, t_working_info *info)
// {
// 	struct stat	file_stat;

// 	expand_homepath(&cmd->simple_cmd->string_value, info);
// 	if (stat(cmd->simple_cmd->string_value, &file_stat) == 0)
// 		return (TRUE);
// 	return (FALSE);
// }
