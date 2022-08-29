/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:44:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/29 21:58:42 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	main_loop(t_envlst *env)
{
	char	*line;
	t_token	*lst_token;
	// t_cmd	*lst_cmd;
	while (1)
	{
		line = readline("MINISHELL : ");
		if (line != NULL)
		{
			// quote의 짝이 맞는지에 대한 에러검사를 tokenize를 들어가기 전에 합니다.
			lst_token = tokenize(line);
			expander(&lst_token, env);
			combine_redirect_filename(lst_token);
			debug_print_lst_token(lst_token);
		}
		else
			ft_error_exit(0, "exit");
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_envlst	*env;

	env = NULL;
	argument_error_check(argc);
	init_envp(envp, &env);
	built_in_env(env);
	main_loop(env);
	return (0);
}
