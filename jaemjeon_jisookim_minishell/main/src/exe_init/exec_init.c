/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 23:09:44 by jisookim         ###   ########.fr       */
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
	while (i < exec->count_key)
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
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env, char **envp)
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
	exec->env = env;
	exec->env_head = exec->env; 
	exec->process_cnt = count_process(exec);
	get_token_count(exec);
	make_env_double_ptr(exec);
	make_path_list(exec);
	return (exec);
}


// ======================================================

// to do : i라ㅇ j랑 잘  해해봐봐!!!! ㅠㅠㅠㅠㅠ
// set_exec_struct_final_cmd_loop & set_exec_struct_final_cmd_str
//
void	set_exec_struct_final_cmd_loop(t_exec *exec, char *cmd_str, int i, int j)
{
	cmd_str = ft_strdup(exec->cmds->simple_cmd->string_value);
	exec->final_cmd_str[i] = ft_strdup(cmd_str); 
	free(cmd_str);
	return ;
}

void	set_exec_struct_final_cmd_str(t_exec *exec, int j) // j == process number
{
	int		i;
	char	*cmd_str;

	i = 0;
	dprintf(2, "process cnt!!!!! (j): %d\n", j);
	exec->final_cmd_str = ft_calloc(1, sizeof(char *) * (exec->token_cnt[j] + 1));
	exec->final_cmd_str[exec->token_cnt[j]] = NULL;
	if (!exec->final_cmd_str)
		ft_exit(exec);
	exec->cmds = exec->cmd_head;
	while (exec->cmds->simple_cmd->string_value)
	{
		set_exec_struct_final_cmd_loop(exec, cmd_str, i, j);
		if (exec->cmds->simple_cmd->next)
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
		else
			break;
		i++;
	}
	set_exec_struct_final_cmd_loop(exec, cmd_str, i, j);
	// exec->final_cmd_str[++j] = NULL;
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
		ft_exit(exec);
	i = 0;
	while (exec->path_lst[i])
	{
		temp = (char *)ft_calloc(1, ft_strlen(exec->path_lst[i]) \
									+ ft_strlen(slash_cmd) + 1);
		temp = ft_strjoin(exec->path_lst[i], slash_cmd);
		if (!temp)
			ft_exit(exec);
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


int	init_exec_struct(t_exec *exec, int process_number)
{
	char *temp;
	//check redirection
	
	set_exec_struct_final_cmd_str(exec, process_number);

	// debug
	dprintf(2, "\n\n=============[%d] EXEC DEBUG ============\n", process_number);
	int idx = 0;
	dprintf(2, "process_number : %d\n", process_number);
	dprintf(2, "exec->process_cnt: %d\n", exec->process_cnt);
	
	while (idx <= exec->token_cnt[process_number]) 
	{
		dprintf(2, "exec->final_cmd_str[%d] : %s\n", idx, exec->final_cmd_str[idx]);
		idx++;
	}
	dprintf(2, "exec->final_cmd_str[%d] : %s (last)\n", idx, exec->final_cmd_str[idx]); // needs to have (null);
	dprintf(2, "=============EXEC DEBUG ============\n\n");
	// debug

	exec->final_path = set_final_path_str(exec);

	return (0);
}
