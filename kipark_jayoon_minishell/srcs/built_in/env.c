/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:46:51 by kipark            #+#    #+#             */
/*   Updated: 2022/10/06 11:24:20 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"env.h"

int	built_in_env(t_env *env)
{
	int	env_exit_status;

	print_env_list(env);
	return (env_exit_status = 0);
}
