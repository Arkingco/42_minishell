/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:31:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/14 16:25:34 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strtok_in_envp(char *envp)
{
	static int	call_count = 0;
	static char	*p_del = NULL;
	static char	*malloced_key = NULL;
	static char	*malloced_value = NULL;

	call_count = (call_count + 1) % 2;
	if (call_count % 2 == 1)
	{
		if (envp == NULL)
			return (NULL);
		p_del = ft_strchr(envp, '=');
		*p_del = '\0';
		malloced_key = ft_strdup(envp);
		malloced_value = ft_strdup(p_del + 1);
		if (malloced_key == NULL || malloced_value == NULL)
			ft_error("malloced fail in func strtok_in_envp\n");
		*p_del = '=';
		return (malloced_key);
	}
	else
		return (malloced_value);
}

void	get_envp(char *envp[])
{
	t_envlst	*envlst;
	char		*key;
	char		*value;

	envlst = ft_env_lstnew("", "");
	getset_info(SET, e_envp, envp);
	while (*envp != NULL)
	{
		key = strtok_in_envp(*envp);
		value = strtok_in_envp(NULL);
		if (ft_strncmp(key, "PATH", INT_MAX) == 0)
			getset_info(SET, e_pathp, value);
		ft_env_lstadd_back(&envlst, ft_env_lstnew(key, value));
		free(key);
		free(value);
		envp++;
	}
	getset_info(SET, e_envlst, envlst);
}

void	init_parsing(int argc, char *argv[], char *envp[])
{
	char	*str;

	if (argc == 1)
	{
		getset_info(SET, e_login_name, "babo");
		getset_info(SET, e_prompt, "babo's minishell > ");
	}
	else if (argc == 2)
	{
		str = ft_strjoin(argv[1], "'s minishell > ");
		getset_info(SET, e_login_name, argv[1]);
		getset_info(SET, e_prompt, str);
		free(str);
	}
	else
		ft_error("argument error\n");
	get_envp(envp);
	set_signal_action();
}
