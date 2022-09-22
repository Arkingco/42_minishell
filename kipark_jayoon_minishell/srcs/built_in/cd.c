/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:27 by kipark            #+#    #+#             */
/*   Updated: 2022/09/21 01:51:01 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"
#include"built.h"
#include"env.h"

void	built_in_cd(t_simple_cmd *simple_cmd, t_env *env)
{
	t_simple_cmd	*this_simple_cmd;

	this_simple_cmd = this_simple_cmd->next;

}