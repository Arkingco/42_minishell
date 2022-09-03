/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_final_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:59:42 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/03 17:40:53 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_paths_from_env(t_exec *exec, char *path_list)
{
	t_exec	*env_head;

	env_head = exec->env;
	while (exec->env->key != "PATH")
	{
		exec->env = exec->env->next;
	}
	path_list = exec->env->value;
	exec->env = env_head;
	return (path_list);
}

char	*ft_split_paths(t_exec *exec, char *path_list, char **temp_path_lists)
{
	temp_path_lists = ft_split(path_list, ':');
	if (!temp_path_lists)
	{
		ft_putstr_fd("ERROR : ft_split() function error! \n", 2);
		ft_double_free(temp_path_lists);
		exit(BAD_EXIT);
	}
	return (temp_path_lists);
}

char	*get_final_path(t_exec *exec, char **temp_path_lists)
{
	int	i;
	char		*temp;
	char		*slash_cmd;
	struct stat	*buf;
	
	slash_cmd = ft_strjoin("/", exec->cmds->simple_cmd->string_value);
	if (!(slash_cmd))
		exit(1);
	i = 0;
	while (temp_path_lists[i])
	{
		temp = ft_calloc(1, sizeof(temp_path_lists[i]) + sizeof(slash_cmd) + 1);
		temp = ft_strjoin(temp_path_lists[i], slash_cmd);
		if (!temp)
			exit(BAD_EXIT);
		if (!ft_stat(temp, buf))
			return (temp);
		free(temp);
		i++;
	}
	free(slash_cmd);
	return (NULL);
}

void	main_get_final_paths(t_exec *exec)
{
	char	*path_list;
	char	**temp_path_lists;
	
	path_list = get_paths_from_env(exec, path_list);
	temp_path_lists = ft_split_paths(exec, path_list, temp_path_lists);
	exec->final_path = get_final_path(exec, temp_path_lists);
}
