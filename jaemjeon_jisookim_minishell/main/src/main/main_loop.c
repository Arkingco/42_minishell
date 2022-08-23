/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:43:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 22:32:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_get_commandline(t_envlst *env)
{
	char	*line;
	t_cmd	*lst_cmd;

	while (1)
	{
		line = readline("MINISHELL : ");
		if (line == NULL)
			ft_error(0, "exit");
		lst_cmd = parsing(line);
		/*
		cmd_list를 테스트하는 코드가 들어갈 것입니다!!.
		*/
		add_history(line);
		free(line);
	}
}
