/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 17:23:22 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "built.h"
#include "libft.h"
#include "env.h"

static void	print_export(t_env *env)
{
	// print 하기 "declare -x " 붙여서
	// 종료 상태 업데이트 싱글 커맨드면 그냥 업데이트 fork받은 값이면 exit으로 나가야함 ...
	char 	*env_key;
	char 	*env_value;
	t_env 	*this_env;
	int		env_key_size;

	this_env = env->next;
	while (this_env)
	{
		env_key_size = get_env_key_size(this_env->str);
		env_key = ft_substr(this_env->str, 0, env_key_size);
		env_value = ft_substr(this_env->str, \
					get_equal_location(this_env->str) + 1, \
					ft_strlen(this_env->str));
		printf("declare -x %s=\"%s\"\n", env_key, env_value);
		this_env = this_env->next;
	}
}

static void execute_export(t_simple_cmd *simple_cmd, t_env *env)
{
	// - epoxrt key=vaule → 가능
	// - export 중복된key=value → 업데이트
	// - export key= → 가능
	// - epoxrt key → 불가능
	int	equal_location;

	equal_location = get_equal_location(simple_cmd->str);
	if (equal_location) // equal 이 있으면 여기 
		env_add(env, simple_cmd->str);
	else				// 없다면 sytax 에러
		printf("export format wrong");
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