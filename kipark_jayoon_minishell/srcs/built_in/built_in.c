/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:26:41 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 15:48:53 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"parser.h"
#include"libft.h"

int is_built_in(t_simple_cmd *simple_cmd)
{
	if (!ft_strncmp(simple_cmd->str, "cd", CD_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "echo", EHCO_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "env", ENV_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "exit", EXIT_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "export", EXPORT_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "pwd", PWD_SIZE + 1))
		return (1);
	if (!ft_strncmp(simple_cmd->str, "unset", UNSET_SIZE + 1))
		return (1);
	return (0);
}

// void	execute_bulit_in(t_simple_cmd *simple_cmd)
// {
// 	if (ft_strncmp(simple_cmd->str, "cd", ft_strlen("cd") + 1))
// 		built_in_cd();
// 	if (ft_strncmp(simple_cmd->str, "echo", ft_strlen("echo") + 1))
// 		built_in_echo();
// 	if (ft_strncmp(simple_cmd->str, "env", ft_strlen("env") + 1))
// 		built_in_env();
// 	if (ft_strncmp(simple_cmd->str, "exit", ft_strlen("exit") + 1))
// 		built_in_exit();
// 	if (ft_strncmp(simple_cmd->str, "export", ft_strlen("export") + 1))
// 		built_in_export();
// 	if (ft_strncmp(simple_cmd->str, "pwd", ft_strlen("pwd") + 1))
// 		built_in_pwd();
// 	if (ft_strncmp(simple_cmd->str, "unset", ft_strlen("unset") + 1))
// 		built_in_unset();
// 	return ;
// }