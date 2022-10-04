/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:39:37 by kipark            #+#    #+#             */
/*   Updated: 2022/10/04 10:51:07 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "here_doc.h"
#include <readline/readline.h>
#include <readline/history.h>

void	here_doc_sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		exit(1);
	}
}

void set_here_doc_sig_handler()
{
	signal(SIGINT, here_doc_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
