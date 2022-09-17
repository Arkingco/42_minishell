/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:35:05 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 02:35:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void	heredoc_process_sigint_process(int signo)
{
	if (signo == SIGINT)
		exit(1);
}


void	doing_heredoc_sigint_process(int signo)
{
	if (signo == SIGINT)
		write(2, "\n", 1);
}
