/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:37:01 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/05 21:05:40 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

static void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	set_terminal_prompt_sigint(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

static void	set_terminal_sig_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	set_terminal_sig_handler_here_doc(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	init_terminal(t_terminal_type t_type)
{
	if (t_type == DEFAULT_TERMINAL)
	{
		set_terminal_sig_handler();
		set_terminal_prompt_sigint();
	}
	else if (t_type == HERE_DOC_TERMINAL)
	{
		set_terminal_sig_handler_here_doc();
		return ;
	}
}
