/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:10:39 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/13 23:21:33 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command_in_path(char **command, char *argv)
{
	char	**path;
	char	*exe_path;
	char	*tmp;

	path = getset_info(GET, e_pathp, NULL);
	if (path == NULL)
		ft_error("not inited path\n");
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		exe_path = ft_strjoin(tmp, command[0]);
		execve(exe_path, command, NULL);
		free(tmp);
		free(exe_path);
		path++;
	}
}