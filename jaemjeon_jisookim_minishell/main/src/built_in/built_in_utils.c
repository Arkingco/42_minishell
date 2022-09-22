/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:44:52 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/14 04:52:01 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_chdir(char *path)
{
	int	ret_chdir;

	ret_chdir = chdir(path);
	if (ret_chdir == FAIL)
		perror("error in chdir.. : ");
	return (ret_chdir);
}

char	*ft_getcwd(char *buf, size_t buf_size)
{
	char	*cwd;

	cwd = getcwd(buf, buf_size);
	if (cwd == NULL)
		perror("error in getcwd.. : ");
	return (cwd);
}