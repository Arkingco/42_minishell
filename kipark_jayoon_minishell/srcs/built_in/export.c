/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 15:44:57 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "built.h"
#include "env.h"
#include "libft.h"
#include "env.h"

static int	is_correct_export_syntax(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
		return (0);
	while (str[i] != '\0' && str[i] != '=')
	{
		if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static int	execute_export(t_simple_cmd *simple_cmd, t_env *env)
{
	int	export_error;

	export_error = 0;
	while (simple_cmd)
	{
		if (is_correct_export_syntax(simple_cmd->str))
			env_add(env, simple_cmd->str);
		else
		{
			ft_multi_putendl_fd("minishell: export: '", simple_cmd->str, \
												"': not a valid identifier", 2);
			export_error = 1;
		}
		simple_cmd = simple_cmd->next;
	}
	return (export_error);
}

static void	print_export(t_env *env)
{
	t_env	*this_env;

	this_env = env->next;
	while (this_env)
	{
		if (this_env->value == NULL)
			printf("declare -x %s\n", this_env->key);
		else
			printf("declare -x %s=\"%s\"\n", this_env->key, this_env->value);
		this_env = this_env->next;
	}
}

int	built_in_export(t_simple_cmd *simple_cmd, t_env *env)
{
	int	export_exit_status;

	export_exit_status = 0;
	if (simple_cmd->next == NULL)
	{
		print_export(env);
		return (export_exit_status = 0);
	}
	else
		return (export_exit_status = execute_export(simple_cmd->next, env));
}
