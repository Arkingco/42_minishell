/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:51:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 12:55:38 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_cur_path(t_working_info *info)
{
	info->cur_path = getcwd(NULL, 0);
	if (info->cur_path == NULL)
		perror("initiating minishell.. error in getcwd..");
	else
		ft_setenv(info->env, "PWD", info->cur_path, TRUE);
	// info->dp = opendir(info->cur_path);
	// if (info->dp == NULL)
	// 	perror("initiating minishell.. error in opendir..");
	ft_delenv(&info->env, "OLDPWD");
}

void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "too many arguments");
}

void	update_shlvl(t_envlst **env)
{
	t_envlst	*env_shlvl;
	int			shlvl_value_int;
	char		*shlvl_value_string;

	env_shlvl = ft_getenv_lst(*env, "SHLVL");
	if (env_shlvl == NULL)
		ft_addenv_str(env, "SHLVL=1");
	else
	{
		shlvl_value_int = ft_atoi(env_shlvl->value);
		shlvl_value_int++;
		shlvl_value_string = ft_itoa(shlvl_value_int);
		ft_setenv(*env, "SHLVL", shlvl_value_string, TRUE);
		free(shlvl_value_string);
	}
}

void	init_envp(t_working_info *info, char *envp[])
{
	info->env = NULL;
	while (*envp != NULL)
	{
		ft_addenv_str(&info->env, *envp);
		envp++;
	}
	update_shlvl(&info->env);
}
