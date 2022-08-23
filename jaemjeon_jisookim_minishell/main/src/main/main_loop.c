/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:43:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/19 14:45:29 by jisookim         ###   ########.fr       */
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
		parsing(line);
		add_history(line);
		free(line);
	}
}
