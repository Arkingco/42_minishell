/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:43:19 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_shlvl(t_envlst *env)
{
	int		int_val_shlvl;
	char	*charp_val_shlvl;

	if (ft_has_env(env, "SHLVL") == FALSE)
		ft_addenv(env, "SHLVL", "1");
	else
	{
		int_val_shlvl = ft_atoi(ft_getenv(env, "SHLVL"));
		int_val_shlvl++;
		charp_val_shlvl = ft_itoa(int_val_shlvl);
		if (charp_val_shlvl == NULL)
			ft_error(1, "malloc failed in ft_itoa of updata_shlvl");
		ft_setenv(env, "SHLVL", charp_val_shlvl);
		free(charp_val_shlvl);
	}
}

void	init_env_lst(char *envp[], t_envlst *env)
{
	while (*envp != NULL)
	{
		ft_addenv_str(env, *envp);
		envp++;
	}
}

void	init(int argc, char *envp[], t_envlst *env)
{
	if (argc != 1)
		ft_error(2, "error in argument");
	set_signal_action();
	init_env_lst(envp, env);
	update_shlvl(env);
}
