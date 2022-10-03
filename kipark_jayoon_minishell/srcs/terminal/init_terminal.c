/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:37:01 by jayoon            #+#    #+#             */
/*   Updated: 2022/10/03 17:54:07 by kipark           ###   ########seoul.kr  */
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
	if (signum != SIGINT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	set_terminal_prompt_sigint()
{
	struct termios  term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

static void	set_terminal_sig_handler()
{
	signal(SIGINT, sig_handler);
}

// ctrl + \ ignore 해결해야 함
void	init_terminal(void)
{
	set_terminal_sig_handler();
	set_terminal_prompt_sigint();
}
