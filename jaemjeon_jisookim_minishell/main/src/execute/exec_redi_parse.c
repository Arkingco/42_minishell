/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redi_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:26:17 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/10 16:36:34 by jisookim         ###   ########.fr       */
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
			fd = ft_open(redi->string_value, O_RDONLY, -1); // open files
			ft_close(fd); // close files
			redi = redi->next;
		}
	}
	return ;
}

char	*exec_find_redi_file(t_exec *exec, t_token *redi, int *more_redi_flag)
{
	t_token	*redi_head;

	redi_head = redi;
	while (redi->string_value)
	{
		if (!redi->next)
		{
			redi = redi_head;
			return (redi->string_value);
		}
		else
		{
			redi = redi->next;
			*more_redi_flag = 1;
		}
	}
	return (NULL);
}

// change input, output file stream by using dup2
char	*get_redi_execute_file(t_exec *exec, t_token *redi, int i)
{
	t_token	*redi_head;
	char	*is_exec_file;
	int		more_redi_flag;
	int		exec_file_fd;

	redi_head = redi;
	is_exec_file = NULL;
	more_redi_flag = 0;
	is_exec_file = exec_find_redi_file(exec, redi, &more_redi_flag); //find exec file
	dprintf(2, "is_exec_file : %s\n", is_exec_file);
	
	if (!is_exec_file)
	{
		dprintf(2, "no file!!!\n");
		return (0);
	}
	if (more_redi_flag)
	{
		redi_open_before_exec_file(exec, redi); //open file before exec file executes.
	}
	
	redi = redi_head;
	return (is_exec_file);
}
