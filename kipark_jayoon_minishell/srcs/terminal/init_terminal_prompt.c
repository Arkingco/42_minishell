/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:54:38 by kipark            #+#    #+#             */
/*   Updated: 2022/10/07 17:32:19 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <termios.h>

void	set_terminal_prompt_sigint_not_print(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	set_terminal_prompt_sigint_print(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}
