/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_final_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:59:42 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/06 01:00:23 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// char	*get_paths_from_env(t_exec *exec, char *path_list)
// {
// 	t_envlst	*env_head;
// 	int			i;

// 	env_head = exec->env;
// 	printf("env_head: %p\n", &env_head);
// 	printf("exec->env: %p\n", &exec->env);
// 	i = 0;
// 	printf("envlst[%d] : %s \n", i, exec->env->key);
// 	while (exec->env->key)
// 	{
// 		printf("envlst[%d] : %s \n", i, exec->env->key);
// 		if (ft_strnstr(exec->env->key, "PATH=", 5))
// 		{
// 			printf("get path!\n");
// 			break;
// 		}
// 		i++;
// 		printf("next!\n");
// 	}
// 	printf("22\n");
// 	path_list = ft_strdup(exec->env->value);
// 	printf("33\n");
// 	exec->env = env_head;
// 	printf("path list : %s\n", path_list);
// 	return (path_list);
// }

// char	**ft_split_paths(t_exec *exec, char *path_list, char **temp_path_lists)
// {
// 	temp_path_lists = ft_split(path_list, ':');
// 	if (!temp_path_lists)
// 	{
// 		ft_putstr_fd("ERROR : ft_split() function error! \n", 2);
// 		ft_double_free(temp_path_lists);
// 		exit(BAD_EXIT);
// 	}
// 	return (temp_path_lists);
// }

// char	*get_final_path(t_exec *exec, char **temp_path_lists)
// {
// 	int	i;
// 	char		*temp;
// 	char		*slash_cmd;
	
// 	slash_cmd = ft_strjoin("/", exec->execve_cmds[0]);
// 	if (!(slash_cmd))
// 		exit(1);
// 	i = 0;
// 	while (temp_path_lists[i])
// 	{
// 		temp = ft_calloc(1, sizeof(temp_path_lists[i]) + sizeof(slash_cmd) + 1);
// 		temp = ft_strjoin(temp_path_lists[i], slash_cmd);
// 		if (!temp)
// 		{
// 			free(temp);
// 			exit(BAD_EXIT);
// 		}
// 		if (ft_stat(temp) == 0)
// 			return (temp);
// 		free(temp);
// 		i++;
// 	}
// 	free(slash_cmd);
// 	return (NULL);
// }

// void	main_get_final_paths(t_exec *exec)
// {
// 	char	*path_value;
// 	char	**temp_path_lists;
	
// 	printf("aa\n");
// 	path_value = get_paths_from_env(exec, path_value); // todo : seg
// 	printf("bb\n");
// 	temp_path_lists = ft_split_paths(exec, path_value, temp_path_lists); // todo : seg
// 	printf("cc\n");
// 	exec->final_path = get_final_path(exec, temp_path_lists); // todo : seg
// 	printf("dd\n");
// }
