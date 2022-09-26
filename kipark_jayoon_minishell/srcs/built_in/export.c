/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 12:34:02 by kipark           ###   ########seoul.kr  */
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
	if (ft_isdigit(str[0]))
		return (0);
	str++;
	while (str[i] != '\0' && str[i] != '=')
	{
		if(!ft_isdigit(str[i]) && !ft_isalpha(str[i]))
			return (0);
		++i;	
	}
	return (1);
}

static void	print_export(t_env *env)
{
	t_env	*this_env;

	this_env = env->next;
	while (this_env)
	{
		printf("declare -x %s=\"%s\"\n", this_env->key, this_env->value);
		this_env = this_env->next;
	}
}

static void	execute_export(t_simple_cmd *simple_cmd, t_env *env)
{
	while (simple_cmd)
	{
		if (is_correct_export_syntax(simple_cmd->str))
			env_add(env, simple_cmd->str);
		else
		{
			ft_multi_putendl_fd("bash: export: '", simple_cmd->str, \
												"': not a valid identifier", 2);
			// error status 1로 핸들링 하기
			break ;
		}
		simple_cmd = simple_cmd->next;
	}
}

void	built_in_export(t_simple_cmd *simple_cmd, t_env *env)
{
	if (simple_cmd->next == NULL)
	{
		print_export(env);
		return ;
	}
	else
		execute_export(simple_cmd->next, env);
	//
	// error handle
	//
}
