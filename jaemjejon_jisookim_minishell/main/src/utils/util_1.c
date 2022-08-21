/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:59:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 19:36:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/variables/var_base_struct.h"

void	ft_error(int exit_status, char *message)
{
	ft_putendl_fd(message, 2);
	exit(exit_status);
}

void	ft_free_envp(char **envp)
{
	if (envp == NULL)
		ft_error(1, "null guard");
	// 2차원배열 할당해제하는 코드
}
