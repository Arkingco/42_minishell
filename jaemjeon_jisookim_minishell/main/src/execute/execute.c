/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/10 16:04:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_built_in(t_cmd *cmd, int cmd_type, t_envlst *env)
{
	void	(*built_in_func);
	static const void (*built_in_func_board[BUILT_IN_COUNT])(t_cmd, t_envlst) = {
		[T_ECHO] = ft_echo,
		[T_CD] = ft_cd,
		[T_PWD] = ft_pwd,
		[T_EXPORT] = ft_export,
		[T_UNSET] = ft_unset,
		[T_ENV] = ft_env,
		[T_EXIT] = ft_exit
	}

	built_in_func = 
}

void	process_single_cmd(t_cmd *cmd, t_envlst *env)
{
	int	cmd_type;

	cmd_type = get_cmd_type(cmd);
	if (cmd_type == NOT_BUILT_IN)
	{

	}
	else
		process_built_in(cmd, cmd_type, env);
}

void	process_multi_cmd(t_cmd *cmd, t_envlst *env)
{

}

void	execute(t_cmd *cmd, t_envlst *env)
{
	int	cmd_count;

	cmd_count = ft_cmdlst_size(cmd);
	if (cmd_count == 0)
		return ;
	else if (cmd_count == 1)
		process_single_cmd(cmd, env);
	else
		process_multi_cmd(cmd, env);
}
