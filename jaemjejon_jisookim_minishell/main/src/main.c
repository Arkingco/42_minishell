/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 19:37:06 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/variables/var_base_struct.h"

t_global	g_global;

int	main(int argc, char *argv[], char *envp[])
{
	init(argc, envp);
	loop_get_commandline(); //utils
	return (0);
}
