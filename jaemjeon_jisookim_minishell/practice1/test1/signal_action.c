/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:56:17 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/13 22:19:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int signo)
{
	signo++;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_signal_action(void)
{
	struct sigaction	sigint_action;
	struct sigaction	sigquit_action;
	struct sigaction	sigstop_action;
	struct termios		term_setting;

	sigint_action.sa_flags = SA_SIGINFO;
	sigint_action.sa_handler = sigint_handler;
	sigquit_action.sa_flags = SA_SIGINFO;
	sigquit_action.sa_handler = SIG_IGN;
	sigstop_action.sa_flags = SA_SIGINFO;
	sigstop_action.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sigint_action, NULL);
	sigaction(SIGQUIT, &sigquit_action, NULL);
	sigaction(SIGTSTP, &sigstop_action, NULL);
	tcgetattr(1, &term_setting);
	term_setting.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term_setting);
}
