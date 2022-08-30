/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:47:08 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/30 14:50:24 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*add_path_with_cmd(t_exec *exec, char **raw_paths)
{
	char	*slash_cmd;
	char	*temp;
	int		i;

	slash_cmd = ft_strjoin("/", exec->cmds[0]);
	if (!(slash_cmd))
		ft_error("Join error. ", 127);
	i = 0;
	while (raw_paths[i])
	{
		temp = (char *)ft_malloc(ft_strlen(raw_paths[i]) \
									+ ft_strlen(slash_cmd) + 1);
		temp = ft_strjoin(raw_paths[i], slash_cmd);
		if (!temp)
			error_exit("Join error. ", 127);
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

char	*get_path_lst(t_envlst *env, t_exec *exec)
{
	int		i;
	char	**envp_temp;

	i = 0;
	while (env->key)
	{
		if (ft_strnstr(env->key, "PATH", 4))
		{
			envp_temp = ft_split(env->value, ':');
			if (!envp_temp)
				ft_error();
			exec->final_path = add_path_with_cmd(exec, envp_temp);
			free(envp_temp);
			return (exec->final_path);
		}
	}
	return (NULL);
}

void	do_execute(t_envlst *env, t_cmd *cmd,t_exec *exec, char *argv_cmd)
{
	int	flag;

	flag = 0;
	exec->cmds = cmd->simple_cmd;
	exec->final_path = get_path_lst(env, exec); // path 파싱해서 가져온 값
	if (exec->final_path == NULL)
		exec->final_path = exec->cmds[0];
	flag = execve(exec->final_path, exec->cmds, exec->envp);
	if (flag < 0)
		ft_error("Exit with error due to execve() or command not found! ", 127);
}
