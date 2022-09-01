/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:47:08 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/01 14:02:15 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"





char	*search_path_lst(t_envlst *env, t_exec *exec)
{
	char	*raw_path_lst;

	while (env->key)
	{
		if (ft_strnstr(env->key, "PATH", 4))
		{
			raw_path_lst = get_raw_path_lst(env, exec);
			return (raw_path_lst);
		}
		env = env->next;
	}
	return (NULL);
}

char	*get_raw_path_lst(t_envlst *env, t_exec *exec)
{
	char **env_temp;

	env_temp = ft_split(env->value, ':');
	if (!env_temp)
		ft_error();
	return (env_temp);
}

int	count_path(t_envlst *env)
{
	int	i;
	int	num;

	i = 0;
	while (env->key && ft_strnstr(env->key, "PATH", 4))
	{
		while (env->value[i])
		{
			if (env->value[i] == ':')
				num++;
			i++;
		}
		env = env->next;
	}
	
	return (num + 1);
}

char	*put_slash_to_cmd(t_envlst *env, t_exec *exec, int i)
{
	

	// get raw path list from search_path_lst()
	
	{
		 = ft_strjoin(env_temp[i], "/");
		i++;
	}
	return (env_temp)
}

// add path with slash cmd
char	*add_path_with_cmd(t_envlst *env, t_exec *exec, char **raw_paths)
{
	int		path;
	char	**env_temp;
	char	*slash_cmd;
	char	*temp;
	int		i;
		
	i = 0;
	path = count_path(env);
	env_temp = search_path_lst(env, exec);
	while (i < path)
	{
		slash_cmd = put_slash_to_cmd(env, exec, i);
		temp = (char *)ft_malloc(ft_strlen(raw_paths[i]) \
									+ ft_strlen(slash_cmd) + 1);
		temp = ft_strjoin(raw_paths[i], slash_cmd);
		if (!temp)
			error_exit();
		if (access(temp, X_OK) == 0) // 해당 함수 쓸수 있는지 확인
		{
			exec->final_path = temp;
			return (exec->final_path);
		}
		free(temp);
		i++;
	}
	free(slash_cmd);
	return (NULL);
}


// check access -> return 

char	*find_path(t_envlst *env, t_exec *exec,t_cmd *cmds)
{

}