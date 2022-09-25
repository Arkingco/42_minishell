/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:27 by kipark            #+#    #+#             */
/*   Updated: 2022/09/25 14:42:18 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"
#include"built.h"
#include"env.h"
#include"libft.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	update_pwd(t_env *env)
{
	char	*curr_pwd;
	char	*new_pwd;

	curr_pwd = getcwd(NULL, 0);
	new_pwd = ft_safe_strjoin("PWD=", curr_pwd);
	env_add(env, new_pwd);
	free(curr_pwd);
	free(new_pwd);
}

void	built_in_cd(t_simple_cmd *simple_cmd, t_env *env)
{
	int	chdir_status;	

	if (simple_cmd->next == NULL)
		return ;
	simple_cmd = simple_cmd->next;
	chdir_status = chdir(simple_cmd->str);
	if (chdir_status == 0)
		update_pwd(env);
	else
		ft_putendl_fd(strerror(errno), 2);
	//
	// exit_status 핸들링
	//
	return ;
}
