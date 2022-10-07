/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:37:01 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/07 17:32:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <termios.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "terminal.h"
#include "libft.h"
#include "exit_status.h"

static void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_exit_status = 1;
	}
}

static void	set_terminal_sig_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	set_terminal_sig_ign(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	init_terminal(t_terminal_type t_type)
{
	if (t_type == DEFAULT_TERMINAL)
	{
		set_terminal_sig_handler();
		set_terminal_prompt_sigint_not_print();
	}
	else if (t_type == HERE_DOC_TERMINAL || t_type == EXECUTE_TERMINAL)
	{
		set_terminal_sig_ign();
		return ;
	}
}
