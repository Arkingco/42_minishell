/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_built_in.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:58:46 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 18:04:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"
#include "execution.h"
#include "libft.h"
#include "parser.h"

static void	save_standard_fd(int *temp_fd)
{
	temp_fd[0] = dup(0);
	temp_fd[1] = dup(1);
	safe_dup2(0, temp_fd[0]);
	safe_dup2(1, temp_fd[1]);
}

void	run_single_built_in(t_parsing_list *l_parsing, t_info_cmd *info_cmd, \
													int *fd, t_env *l_head_env)
{
	int	temp_fd[2];
	int	is_success;

	is_success = 1;
	save_standard_fd(temp_fd);
	if (l_parsing->redir_iter)
		is_success = parent_init_fd_redir(l_parsing->redir_iter, fd,
				info_cmd->l_here_doc);
	if (is_success)
	{
		if (fd[1] != 1)
		{
			safe_dup2(fd[1], 1);
			safe_close(fd[1]);
		}
		if (fd[2] != 0)
		{
			safe_dup2(fd[2], 0);
			safe_close(fd[2]);
		}
		execute_bulit_in(l_parsing->l_simple_cmd, l_head_env, SINGLE_CMD);
	}
	safe_dup2_and_close(temp_fd[0], 0);
	safe_dup2_and_close(temp_fd[1], 1);
}
