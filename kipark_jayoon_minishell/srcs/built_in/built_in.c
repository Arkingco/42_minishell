/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:26:41 by kipark            #+#    #+#             */
/*   Updated: 2022/10/06 18:27:11 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"env.h"
#include"parser.h"
#include"built.h"
#include"libft.h"
#include"exit_status.h"

int	is_built_in(t_simple_cmd *simple_cmd)
{
	if (!simple_cmd)
		return (0);
	if (!ft_strncmp(simple_cmd->str, "cd", 3))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "echo", 5))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "env", 4))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "exit", 5))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "export", 7))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "pwd", 4))
		return (1);
	else if (!ft_strncmp(simple_cmd->str, "unset", 6))
		return (1);
	return (0);
}

void	execute_bulit_in(t_simple_cmd *simple_cmd, t_env *env, \
											t_execute_cmd_division division_cmd)
{
	int	built_in_exit_status;

	built_in_exit_status = 0;
	if (!ft_strncmp(simple_cmd->str, "cd", 3))
		built_in_exit_status = built_in_cd(simple_cmd, env);
	else if (!ft_strncmp(simple_cmd->str, "echo", 5))
		built_in_exit_status = built_in_echo(simple_cmd);
	else if (!ft_strncmp(simple_cmd->str, "env", 4))
		built_in_exit_status = built_in_env(env);
	else if (!ft_strncmp(simple_cmd->str, "exit", 5))
		built_in_exit_status = built_in_exit(simple_cmd);
	else if (!ft_strncmp(simple_cmd->str, "export", 7))
		built_in_exit_status = built_in_export(simple_cmd, env);
	else if (!ft_strncmp(simple_cmd->str, "pwd", 4))
		built_in_exit_status = built_in_pwd(simple_cmd);
	else if (!ft_strncmp(simple_cmd->str, "unset", 6))
		built_in_exit_status = built_in_unset(simple_cmd, env);
	if (division_cmd == SINGLE_CMD)
		g_exit_status = built_in_exit_status;
	else
		exit(built_in_exit_status);
	return ;
}
