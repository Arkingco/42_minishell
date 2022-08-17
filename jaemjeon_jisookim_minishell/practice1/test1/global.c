/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 02:54:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/07 16:22:53 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*get_info_mem_p(t_info *info, int type)
{
	if (type == e_login_name)
		return (info->login_name);
	else if (type == e_prompt)
		return (info->prompt);
	else if (type == e_envlst)
		return (info->envlst);
	else if (type == e_pathp)
		return (info->pathp);
	return (P_FAIL);
}

void	*set_info_mem(t_info *info, int type, void *p_value)
{
	if (type == e_login_name)
	{
		if (info->login_name != NULL)
			free(info->login_name);
		info->login_name = ft_strdup(p_value);
	}
	else if (type == e_prompt)
	{
		if (info->prompt != NULL)
			free(info->prompt);
		info->prompt = ft_strdup(p_value);
	}
	else if (type == e_pathp)
	{
		if (info->pathp != NULL)
		{
			printf("already seted pathp\n");
			return (NULL);
		}
		info->pathp = ft_split(p_value, ':');
	}
	return (P_SUCCESS);
}

void	*getset_info(int getset, int type, void *p_value)
{
	static t_info	info;

	if (getset == GET)
		return (get_info_mem_p(&info, type));
	else
		return (set_info_mem(&info, type, p_value));
	return (P_FAIL);
}
