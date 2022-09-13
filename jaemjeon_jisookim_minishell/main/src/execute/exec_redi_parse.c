/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redi_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:26:17 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/13 16:33:44 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	redi_open_before_exec_file(t_exec *exec, t_token *redi)
{
	int	fd;

	while (redi->string_value)
	{
		if (!redi->next) // (== last redi)
		{
			return ;
		}
		else
		{
			fd = open(redi->string_value,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				exit (1);
			ft_close(fd); // close files
			redi = redi->next;
		}
	}
	return ;
}

char	*exec_find_redi_file(t_exec *exec, t_token *redi, int *flag, int *type)
{
	while (redi->string_value)
	{
		if (!redi->next)
		{
			*type = redi->type;
			return (redi->string_value);
		}
		else
		{
			redi = redi->next;
			*flag = 1;
		}
	}
	return (NULL);
}

// change input, output file stream by using dup2
char	*get_redi_execute_file(t_exec *exec, t_token *redi, int *type)
{
	char	*is_exec_file;
	int		more_redi_flag;

	is_exec_file = NULL;
	more_redi_flag = 0;
	is_exec_file = exec_find_redi_file(exec, redi, &more_redi_flag, type); //find exec file
	if (!is_exec_file)
		return (0);
	if (more_redi_flag)
	{
		redi_open_before_exec_file(exec, redi); //open file before exec file executes.
	}
	return (is_exec_file);
}

