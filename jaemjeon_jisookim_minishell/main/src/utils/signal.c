/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:38:59 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 14:04:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	sigint_handler_print_newline(int signo)
{
	if (signo == SIGINT)
		write(2, "\n", 1);
}

void	set_signal(int mode)
{
	if (mode == MINISHELL_NO_CHILD)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == MINISHELL_HAS_CHILD)
	{
		signal(SIGINT, sigint_handler_print_newline);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == EXECUTE_CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (mode == HEREDOC_PARENT)
	{
		signal(SIGINT, sigint_handler_print_newline);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == HEREDOC_CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
}
