/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/22 20:54:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

int	main(int argc, char *argv[], char *envp[])
{
	init(argc, envp);
	loop_get_commandline();
	return (0);
	// unused parameter error
	argv++;
	argv = NULL;
}
