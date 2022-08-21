/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:43:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 19:36:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/variables/var_base_struct.h"

void	loop_get_commandline(void)
{
	char	*line;

	while (1)
	{
		line = readline("MINISHELL : ");
		if (line == NULL)
			ft_error(0, "exit");
		//something here!
		add_history(line);
		free(line);
	}
}
