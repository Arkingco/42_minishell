/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:01 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 18:51:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_check_flag()
{
	return (0);
}

int	do_echo(t_exec *exec)
{
	int		ret;
	char	*echo_str;
	
	echo_str = exec->cmds->simple_cmd;
	while (echo_str)
	{
		if (echo_str)
	}
	return (ret);
}

// return : exit(0);
// error return : >0
// 1) check -n / check -nnnnnnn
// 2) check a lot of space/tab -> one space
int	ft_echo(t_exec *exec, int exec_type)
{
	int	ret;
	
	// else if (exec_type == MULTI_CMD && ) // todo: check if its last cmd
	// {
	// 	return (0);
	// }
	if (exec_type == MULTI_CMD)
		return (0);
	else if (exec_type == SINGLE_CMD)
	{
		ret = do_echo(exec);
	}
	if (ret == -1)
	{
		ft_putstr_fd("ERROR : do_echo() function error! \n", 2);
		exit(BAD_EXIT);
	}
	return (0);
}