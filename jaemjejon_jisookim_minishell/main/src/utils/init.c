/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 19:40:43 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/variables/var_base_struct.h"
#include "../../include/variables/var_define.h"

extern t_global	g_global;

void	update_shlvl()
{
	int		int_val_shlvl;
	char	*charp_val_shlvl;

	if (ft_has_env("SHLVL") == FALSE)
		ft_addenv("SHLVL", "1");
	else
	{
		int_val_shlvl = ft_atoi(ft_getenv("SHLVL"));
		int_val_shlvl++;
		charp_val_shlvl = ft_itoa(int_val_shlvl);
		if (charp_val_shlvl == NULL)
			ft_error(1, "malloc failed in ft_itoa of updata_shlvl");
		ft_setenv("SHLVL", charp_val_shlvl);
		free(charp_val_shlvl);
	}
}

void	init_env_lst(char *envp[])
{
	while (*envp != NULL)
	{
		ft_addenv_str(*envp);
		envp++;
	}
}

void	init(int argc, char *envp[])
{
	if (argc != 1)
		ft_error(2, "error in argument");
	set_signal_action();
	init_env_lst(envp);
	update_shlvl();
}
