/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 22:13:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

int	main(int argc, char *argv[], char *envp[])
{
	t_envlst	env;

	init(argc, envp, &env);
	loop_get_commandline(&env);
	return (0);
	// unused parameter error
	argv++;
	argv = NULL;
}
