/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:02:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/13 23:23:55 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_processing(char *command_line)
{
	pid_t	pid;
	int		child_status;
	char	**command_token;
	int		index;

	command_token = ft_split(command_line, ' ');
	if (ft_strncmp(command_token[0], "env", 4) == 0)
		command_env();
	else
	{
		pid = fork();
		if (pid > 0)
			waitpid(pid, &child_status, 0);
		else if (pid == 0)
			run_command_in_path(command_token, NULL);
		else
			ft_error("fork_error\n");
	}
	index = -1;
	while (command_token[++index] != NULL)
		ft_free((void **)&command_token[index]);
	free(command_token);
	return ;
}