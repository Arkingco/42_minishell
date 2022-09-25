/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:26:22 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 12:26:36 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_has_env(t_envlst *env, char *key)
{
	if (ft_getenv_lst(env, key) != NULL)
		return (TRUE);
	else
		return (FALSE);
}


void	ft_setenv(t_envlst *env, char *key, char *value, int has_value)
{
	t_envlst	*envlst_toset;
	
	envlst_toset = ft_getenv_lst(env, key);
	if (envlst_toset == NULL)
		ft_addenv(&env, key, value, has_value);
	else
	{
		if (has_value == FALSE && envlst_toset->has_value == TRUE)
			return ;
		free(envlst_toset->value);
		envlst_toset->value = 0;
		envlst_toset->value = ft_strdup(value);
		if (envlst_toset->value == NULL)
			ft_error_exit(1, "minishell: exit due to malloc failed");
		envlst_toset->has_value = has_value;
	}
}
