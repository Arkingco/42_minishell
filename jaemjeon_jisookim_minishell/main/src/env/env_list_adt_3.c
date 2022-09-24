/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:24:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 19:53:41 by jaemjeon         ###   ########.fr       */
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
		envlst_toset->value = ft_strdup(value);
		if (envlst_toset->value == NULL)
			ft_error_exit(1, "malloc failed in ft_strdup of ft_setenv");
		envlst_toset->has_value = has_value;
	}
}

char	*ft_envlst_to_string(t_envlst *lst)
{
	char	*env_string;
	char	*tmp_string;

	if (lst == NULL)
		ft_error_exit(1, "para input error in ft_envlst_to_string");
	tmp_string = ft_strjoin(lst->key, "=");
	env_string = ft_strjoin(tmp_string, lst->value);
	free(tmp_string);
	return (env_string);
}

char	**ft_envlst_to_envp(t_envlst *env)
{
	char		**envp;
	int			index;
	t_envlst	*envlst;

	envlst = ft_env_lst_first(env);
	envp = (char **)ft_calloc(sizeof(char *), ft_env_lstsize(envlst) + 1);
	if (envp == NULL)
		return (NULL);
	index = 0;
	while (envlst != NULL)
	{
		envp[index] = ft_envlst_to_string(envlst);
		envlst = envlst->next;
		index++;
	}
	return (envp);
}

char	*ft_get_value_in_string(char *string)
{
	char	*delimiter_point;

	delimiter_point = ft_strchr(string, '=');
	if (delimiter_point == NULL)
		return (NULL);
	else if (delimiter_point[1] == '\0')
		return (ft_strdup(""));
	else
	{
		return (ft_substr(delimiter_point, 1, \
								ft_strchr(string, 0) - delimiter_point - 1));
	}
}

char	*ft_get_key_in_string(char *string)
{
	char	*delimiter_point;

	delimiter_point = ft_strchr(string, '=');
	if (delimiter_point == NULL)
		return (ft_strdup(string));
	else
		return (ft_substr(string, 0, delimiter_point - string));
}
