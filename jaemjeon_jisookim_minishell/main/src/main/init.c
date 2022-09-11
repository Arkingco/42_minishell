/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:51:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/12 03:09:09 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "too many arguments");
}

void	init_envp(char *envp[], t_envlst **env)
{
	while (*envp != NULL)
	{
		ft_addenv_str(env, *envp);
		envp++;
	}
}
