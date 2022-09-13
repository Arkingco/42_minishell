/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:51:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/14 03:32:34 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_info(t_working_info *info, t_envlst *env)
{
	info->env = env;
	info->cur_path = getcwd(NULL, 0);
	if (info->cur_path == NULL)
		perror("initiating minishell.. error in getcwd..");
	else
		ft_setenv(env, "PWD", info->cur_path, TRUE);
	info->dp = opendir(info->cur_path);
	if (info->dp == NULL)
		perror("initiating minishell.. error in opendir..");
	ft_delenv(&env, "OLDPWD");
}

void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "too many arguments");
}

void	init_inner_env(t_envlst **env)
{
	// t_envlst	*my_env;

	// getcwd()

	// my_env = ft_getenv_lst(*env, "PWD");
	// if ()
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

void	init_envp(char *envp[], t_envlst **env)
{
	while (*envp != NULL)
	{
		ft_addenv_str(env, *envp);
		envp++;
	}
	update_shlvl(env);
	init_inner_env(env);
}
