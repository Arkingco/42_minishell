/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_get_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/06 01:04:06 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_cmd_count(t_exec *exec)
{
	int	i;

	i = 0;
	printf("process_cnt : %d\n", exec->process_cnt);
	exec->token_cnt = ft_calloc(1, sizeof(int *) * exec->process_cnt);
	if (!exec->token_cnt)
	{
		ft_putstr_fd("ERROR : calloc() function error. \n", 2);
		free(exec->token_cnt);
		exit(1);
	}
	while (i < exec->process_cnt)
	{
		exec->token_cnt[i] = get_simple_cmd_count(exec, i);
		printf(" ::::: exec->token_cnt[%d] : %d :::::\n", i, exec->token_cnt[i]);
		i++;
	}
	return ;
}

int	get_simple_cmd_count(t_exec *exec, int i)
{
	int		j;
	int		cmd_count;
	void	*backup_exec_cmd;
	void	*backup_simple_cmd_head;
	
	j = 0;
	cmd_count = 0;
	backup_exec_cmd = exec->cmds;
	while (j < i) //cmd이동
	{
		exec->cmds = exec->cmds->next;
		j++;
	}
	while (exec->cmds->simple_cmd)  //simple cmd이동
	{
		backup_simple_cmd_head = exec->cmds->simple_cmd;
		if (exec->cmds->simple_cmd->next)
		{
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
			cmd_count++;
		}
		else
		{
			exec->cmds->simple_cmd = backup_simple_cmd_head;
			cmd_count++;
			break ;
		}
	}
	exec->cmds = backup_exec_cmd;
	//printf("+++++++++ cmd_count[%d] : %d\n", i, cmd_count);
	return (cmd_count);
}

char	*get_simple_cmd_str(t_exec *exec, char *dest) {
	int		j;
	char	*ret;
	void	*backup_exec_cmd;
	void	*backup_simple_cmd_head;
	
	j = 0;
	backup_exec_cmd = exec->cmds;
	while (j < i) //cmd이동
	{
		exec->cmds = exec->cmds->next;
		j++;
	}
	while (exec->cmds->simple_cmd)  //simple cmd이동
	{
		backup_simple_cmd_head = exec->cmds->simple_cmd;
		if (exec->cmds->simple_cmd->next)
		{
			exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
			cmd_count++;
		}
		else
		{
			exec->cmds->simple_cmd = backup_simple_cmd_head;
			cmd_count++;
			break ;
		}
	}
	exec->cmds = backup_exec_cmd;
	//printf("+++++++++ cmd_count[%d] : %d\n", i, cmd_count);
	return (ret);
}

void	store_ptr_execve_cmds(t_exec *exec)
{
	int	i;


	i = 0;
	// >>>> broad (process count) mallloc, make 이중포인터 array

	return ;
}

void	make_ptr_execve_cmds(t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	

	// >>>> specify (token count) malloc, make pointer array

	exec->execve_cmds = ft_calloc(1, sizeof(char **) * exec->process_cnt);
	if (!exec->execve_cmds)
	{
		ft_putstr_fd("ERROR : calloc() function error. \n", 2);
		free(exec->execve_cmds);
		exit(1);
	}
	while (i < exec->token_cnt)
	{
		exec->execve_cmds[i] = ft_calloc(1, sizeof(char *) * exec->token_cnt[i] + 1); // divide with cmd
		exec->execve_cmds[i][exec->token_cnt[i]] = '/0';
		exec->execve_cmds[i] = ft_strdup(exec->cmds->simple_cmd)
		i++;
	}
	// if (!exec->execve_cmds[i])
	// {
	// 	ft_putstr_fd("ERROR : calloc() error while making execve_cmds. \n", 2);
	// 	free(exec->execve_cmds[i]);
	// }
	// while (i < exec->cmd_cnt[i])
	// {
	// 	if (exec->cmds->simple_cmd && exec->cmds->simple_cmd->next)
	// 	{
	// 		exec->execve_cmds[i] = ft_strdup(exec->cmds->simple_cmd);
	// 		exec->cmds->simple_cmd = exec->cmds->simple_cmd->next;
	// 	}
	// }
	// i++;
	// free(exec->execve_cmds);
	// exit(1);
}

// 단위 : one cmd, in one process.
char	**init_execve_cmds(t_exec *exec)
{	
	int		i;
	
	i = 0;
	get_cmd_count(exec);
	// i = 0;
	// make_ptr_execve_cmds(exec);
	// while(i < exec->cmd_count && exec->cmds)
	// {
	// 	exec->execve_cmds[i] = exec->cmds->simple_cmd->string_value;
	// 	exec->cmds = exec->cmds->next;
	// 	i++;
	// }
	// exec->execve_cmds[i] = 0;
	// exec->cmds = exec->cmd_head;
	return (exec->execve_cmds);
}
