/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 15:21:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

char	**get_path_board(t_envlst *env)
{
	char	*path_line;
	char	**path_board;

	path_line = ft_getenv(env, "PATH");
	if (path_line == NULL)
		return (NULL);
	path_board = ft_split(path_line, ':');
	if (path_board == NULL)
		ft_error_exit(1, "malloc error in ft_split");
}

char	*get_excv_path(char *cmd_string, t_envlst *env)
{
	char **path;

	path =
}
