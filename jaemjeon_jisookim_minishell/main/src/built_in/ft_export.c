/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:07 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 04:46:45 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_export_env(t_envlst *env)
{
	while (env != NULL)
	{
		printf("declare -x ");
		printf("%s", env->key);
		if (env->has_value == TRUE)
			printf("=%s\n", env->value);
		else
			printf("\n");
		env = env->next;
	}
}

void	add_new_envs(t_token *cmd_argv, t_envlst *env)
{
	char	*envkey_to_input;
	char	*envvalue_to_input;

	while (cmd_argv != NULL)
	{
		envkey_to_input = ft_get_key_in_string(cmd_argv->string_value);
		envvalue_to_input = ft_get_value_in_string(cmd_argv->string_value);
		if (ft_has_env(env, envkey_to_input) == TRUE)
		{
			if (envvalue_to_input == NULL)
				ft_setenv(env, envkey_to_input, "", FALSE);
			else
				ft_setenv(env, envkey_to_input, envvalue_to_input, TRUE);
		}
		else
		{
			if (envvalue_to_input == NULL)
				ft_addenv(&env, envkey_to_input, "", FALSE);
			else
				ft_addenv(&env, envkey_to_input, envvalue_to_input, TRUE);
		}
		free(envkey_to_input);
		if (envvalue_to_input != NULL)
			free(envvalue_to_input);
		cmd_argv = cmd_argv->next;
	}
}

void	ft_export(t_cmd *cmd, t_envlst *env)
{
	t_token *cmd_argv;

	cmd_argv = cmd->simple_cmd->next;
	if (cmd_argv == NULL)
		print_export_env(env);
	else
		add_new_envs(cmd_argv, env);
}
