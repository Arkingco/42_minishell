/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:13:38 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/25 18:48:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_termios(int mode)
{
	struct termios	term_setting;

	tcgetattr(STDOUT_FILENO, &term_setting);
	if (mode == MINISHELL_NO_CHILD || mode == MINISHELL_HAS_CHILD || \
						mode == HEREDOC_PARENT || mode == HEREDOC_CHILD)
		term_setting.c_lflag &= ~(ECHOCTL);
	else if (mode == EXECUTE_CHILD)
		term_setting.c_lflag |= ECHOCTL;
	tcsetattr(STDOUT_FILENO, NONE, &term_setting);
}
