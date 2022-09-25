/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:07 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/26 01:31:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_key_grammar(char *key)
{
	int		i;

	i = 0;
	if (key[i] != '_' && !ft_isalpha(key[0]))
		return (1);
	i = 1;
	while (key[i])
	{
		if (key[i] == '_' || ft_isalnum(key[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	print_export_env(t_envlst *env)
{
	while (env != NULL)
	{
		printf("declare -x ");
		printf("%s", env->key);
		if (env->has_value == TRUE)
			printf("=\"%s\"\n", env->value);
		else
			printf("\n");
		env = env->next;
	}
	return (0);
}

void	free_env_key_and_value(char *envkey_to_input, char *envvalue_to_input)
{
	free(envkey_to_input);
	envkey_to_input = 0;
	if (envvalue_to_input != NULL)
	{
		free(envvalue_to_input);
		envkey_to_input = 0;
	}
}

int	add_new_envs(t_token *cmd_argv, t_envlst *env)
{
	char	*envkey_to_input;
	char	*envvalue_to_input;

	while (cmd_argv != NULL)
	{
		envkey_to_input = ft_get_key_in_string(cmd_argv->string_value);
		if (check_key_grammar(envkey_to_input))
		{
			process_errno(1, cmd_argv->string_value, IDENTIFIER_ERR);
			free(envkey_to_input);
			return (1);
		}
		envvalue_to_input = ft_get_value_in_string(cmd_argv->string_value);
		if (envvalue_to_input == NULL)
			ft_setenv(env, envkey_to_input, "", FALSE);
		else
			ft_setenv(env, envkey_to_input, envvalue_to_input, TRUE);
		free_env_key_and_value(envkey_to_input, envvalue_to_input);
		cmd_argv = cmd_argv->next;
	}
	return (0);
}

int	ft_export(t_cmd *cmd, t_working_info *info)
{
	t_token	*cmd_argv;
	int		error_check_flag;

	error_check_flag = 0;
	cmd_argv = cmd->simple_cmd->next;
	if (cmd_argv == NULL)
		error_check_flag = print_export_env(info->env);
	else
		error_check_flag = add_new_envs(cmd_argv, info->env);
	return (error_check_flag);
}
