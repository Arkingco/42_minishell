/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:14:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 20:00:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "execution.h"
#include "exit_status.h"
#include <fcntl.h>
#include "libft.h"
#include "parser.h"
#include "built.h"
#include "env.h"
#include "signal.h"
#include "terminal.h"

static void	set_signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	do_it_child(t_parsing_list *l_parsing, t_info_cmd *info_cmd, \
													int *fd, t_env *l_head_env)
{
	set_signal_child();
	set_terminal_prompt_sigint_print();
	if (l_parsing->redir_iter)
		init_fd_by_redirection(l_parsing->redir_iter, fd, info_cmd->l_here_doc);
	if (fd[0] != 0 && !is_last_cmd(info_cmd))
		safe_close(fd[0]);
	if (fd[1] != 1)
		safe_dup2_and_close(fd[1], 1);
	if (fd[2] != 0)
		safe_dup2_and_close(fd[2], 0);
	if (l_parsing->l_simple_cmd)
	{
		if (is_built_in(l_parsing->l_simple_cmd))
			execute_bulit_in(l_parsing->l_simple_cmd, l_head_env, MULTI_CMD);
		else
		{
			init_execve_args(l_parsing, &info_cmd->args_execve,
				info_cmd->args_execve.envp);
			execve_cmd(&info_cmd->args_execve, info_cmd->args_execve.envp);
		}
	}
	exit(0);
}
