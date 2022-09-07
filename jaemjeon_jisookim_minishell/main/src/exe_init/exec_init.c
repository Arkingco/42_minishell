/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/06 01:11:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// pipe_cnt = process_cnt -1
int	count_process(t_exec *exec)
{
	int		process;

	process = 0;
	while (exec->cmds)
	{
		process++;
		if (!exec->cmds->next)
			break ;
		if (process == sizeof(int))
		{
			ft_putstr_fd("ERROR : process size too big. ", 2);
			exit(BAD_EXIT);
		}
		exec->cmds = exec->cmds->next;
	}
	exec->cmds = exec->cmd_head; // put back cmd
	return (process);
}

void	make_path_list(t_exec *exec)
{
	int		i;

	i = 0;
	while (exec->env_lst[i])
	{
		if (ft_strnstr(exec->env_lst[i], "PATH=", 5)) //find PATH in env
		{
			exec->path_lst = ft_split((exec->env_lst[i] + 5), ':'); //store path in exec->path_lst
			if (!exec->path_lst)
			{
				ft_putstr_fd("ERROR : error while making list.\n", 2);
				free(exec->path_lst);
				exit(127);
			}
		}
		i++;
	}
	return ;
}

// all of the cmd string
// main cmd
// execve(const char *path, char *const argv[], char *const envp[]);
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env)
{
	exec = ft_calloc(1, sizeof(t_exec));
	if (!exec)
	{
		ft_putstr_fd("ERROR : calloc() function error. ", 2);
		free(exec);
		exit(BAD_EXIT);
	}
	exec->cmds = cmd;
	exec->cmd_head = cmd;
	exec->process_cnt = count_process(exec);
	exec->env = env;
	get_token_count(exec);

	make_env_double_ptr(exec);
	make_path_list(exec);

	return (exec);
}


// ======================================================

void	set_exec_struct_final_cmd_loop(t_exec *exec, char *cmd_str, int i)
{
	cmd_str = ft_strdup(exec->cmds->simple_cmd->string_value);
	exec->final_cmd_str[i] = ft_strdup(cmd_str); 
	free(cmd_str);
	return ;
}

void	set_exec_struct_final_cmd_str(t_exec *exec)
{
	int		i;
	char	*cmd_str;

	i = 0;
	exec->final_cmd_str = ft_calloc(1, sizeof(char *) * exec->process_cnt + 1);
	if (!exec->final_cmd_str)
		ft_exit(1);
	exec->cmds = exec->cmd_head;
	while (exec->cmds->simple_cmd->string_value)
	{
		set_exec_struct_final_cmd_loop(exec, cmd_str, i);
		if (exec->cmds->simple_cmd->next)
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
		else
			break;
		i++;
	}
	set_exec_struct_final_cmd_loop(exec, cmd_str, i);
	exec->final_cmd_str[++i] = 0;
	exec->cmds = exec->cmd_head; // init
	return ;
}


char	*set_final_path_str(t_exec *exec)
{
	char			*slash_cmd;
	char			*temp;
	struct stat		buf;
	int				i;

	slash_cmd = ft_strjoin("/", exec->final_cmd_str[0]);
	if (!(slash_cmd))
		ft_exit(1);
	i = 0;
	while (exec->path_lst[i])
	{
		temp = (char *)ft_calloc(1, ft_strlen(exec->path_lst[i]) \
									+ ft_strlen(slash_cmd) + 1);
		temp = ft_strjoin(exec->path_lst[i], slash_cmd);
		if (!temp)
			ft_exit(127);
		if (!stat(temp, &buf))
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


int	init_exec_struct(t_exec *exec)
{
	int i = 0;
	char *temp;
	//check redirection
	
	set_exec_struct_final_cmd_str(exec);

	// debug
	printf("\n\n============= DEBUG ============\n");
	while (exec->final_cmd_str[i]) 
	{
		printf("exec->final_cmd_str[%d] : %s\n", i, exec->final_cmd_str[i]);
		i++;
	}
	printf("exec->final_cmd_str[%d] : %s\n", i, exec->final_cmd_str[i]); // needs to have (null);
	exec->final_path = set_final_path_str(exec);
	printf("exec->final_path : %s\n", exec->final_path);
	printf("============= DEBUG ============\n\n");
	// debug

	return (0);
}


// pipex
// char	*add_path_with_cmd(t_info *info, char **raw_paths)
// {
// 	char	*slash_cmd;
// 	char	*temp;
// 	int		i;

// 	slash_cmd = ft_strjoin("/", info->cmds[0]);
// 	if (!(slash_cmd))
// 		error_exit("Join error. ", 127);
// 	i = 0;
// 	while (raw_paths[i])
// 	{
// 		temp = (char *)ft_malloc(ft_strlen(raw_paths[i]) \
// 									+ ft_strlen(slash_cmd) + 1);
// 		temp = ft_strjoin(raw_paths[i], slash_cmd);
// 		if (!temp)
// 			error_exit("Join error. ", 127);
// 		if (access(temp, X_OK) == 0)
// 		{
// 			info->final_path = temp;
// 			return (info->final_path);
// 		}
// 		free(temp);
// 		i++;
// 	}
// 	free(slash_cmd);
// 	return (NULL);
// }

// char	*find_available_stat_path(t_exec *exec)
// {
// 	(void) exec;
// 	// char	*path;
// 	// int		i;

// 	// i = 0;
// 	// while (exec->env_lst[i])
// 	// {
// 	// 	if (!stat())		
// 	// }
// 	return (path);
// }

