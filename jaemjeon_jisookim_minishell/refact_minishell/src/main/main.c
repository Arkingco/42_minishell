/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:44:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/27 09:38:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_loop(t_envlst *env)
{
	char	*line;
	// t_token	*lst_token;
	// t_cmd	*lst_cmd;

	while (1)
	{
		line = readline("MINISHELL : ");
		if (line != NULL)
		{
			// t_token = tokenize(line);
			// t_cmd = token_to_cmdlst(t_token);
			// // execute(t_cmd);
			// free_lst_token(lst_token);
			// free_lst_cmd(lst_cmd);
		}
		else
			ft_error_exit(0, "exit");
	}

	// unused para
	env++;
	env = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_envlst	*env;

	env = NULL;
	argument_error_check(argc);
	init_envp(envp, &env);
	env = built_in_env(env); // made to pass env
	main_loop(env);
	return (0);


	// unused para
	argv++;
	argv = NULL;
}