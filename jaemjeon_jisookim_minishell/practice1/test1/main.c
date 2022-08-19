/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:27:52 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/17 03:19:40 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_command_loop(void)
{
	char	*command_line;
	char	*str_pormpt;
	char	*shlvl;

	str_pormpt = getset_info(GET, e_prompt, NULL);
	while (1)
	{
		shlvl = getenv("SHLVL");
		(*shlvl)++;
		printf("%s\n", shlvl);
		command_line = readline(str_pormpt);
		if (command_line == NULL)
			return ;
		else if (command_line[0] == '\0')
		{
			free(command_line);
			continue ;
		}
		command_processing(command_line);
		add_history(command_line);
		free(command_line);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	init_parsing(argc, argv, envp);
	get_command_loop();
	exit(0);
}
