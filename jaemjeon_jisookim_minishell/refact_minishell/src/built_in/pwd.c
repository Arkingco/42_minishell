/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:21:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/27 09:59:47 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// # include <unistd.h>
// # include <stdio.h>
// # include <stdlib.h>

void	pwd()
{
	char	*cwd;
	size_t	buff_size;

	buff_size = 1024;
	cwd = getcwd(NULL, buff_size);
	if (!cwd)
	{
		free(cwd);
		return ;
	}
	printf("%s", cwd);
	free(cwd);
}

// test
// int main()
// {
// 	printf("pwd test :");
// 	pwd();
// }