/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:45 by kipark            #+#    #+#             */
/*   Updated: 2022/09/23 18:01:48 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "built.h"
#include "env.h"
#include "libft.h"
#include "env.h"

static void	print_export(t_env *env)
{
	// print 하기 "declare -x " 붙여서
	// 종료 상태 업데이트 싱글 커맨드면 그냥 업데이트 fork받은 값이면 exit으로 나가야함 ...
	t_env 	*this_env;

	this_env = env->next;
	while (this_env)
	{
		printf("declare -x %s=\"%s\"\n", this_env->key, this_env->value);
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

	equal_location = get_env_equal_location(simple_cmd->str);
	if (equal_location) // equal 이 있으면 여기 
		env_add(env, simple_cmd->str);
	else				// 없다면 sytax 에러
		printf("export format wrong\n");
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