/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:43:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/17 22:30:12 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_get_commandline(void)
{
	char	*line;

	while (1)
	{
		line = readline("MINISHELL : ");
		if (line == NULL)
			ft_error(0, "exit");
		pwd();
		add_history(line);
		free(line);
	}
}
