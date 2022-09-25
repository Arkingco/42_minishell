/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_adt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:24:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 17:35:43 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_envlst_to_string(t_envlst *lst)
{
	char	*env_string;
	char	*tmp_string;

	if (lst == NULL)
		ft_error_exit(1, "minishell: para input error in ft_envlst_to_string");
	tmp_string = ft_strjoin(lst->key, "=");
	env_string = ft_strjoin(tmp_string, lst->value);
	free(tmp_string);
	tmp_string = 0;
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
	{
		envp = 0;
		return (NULL);
	}
	index = 0;
	while (envlst != NULL)
	{
		if (envlst->has_value)
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
