/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 13:27:01 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	main_loop(t_info *info, t_envlst *env, char **envp)
{
	char	*line;
	t_cmd	*lst_cmd;

	while (1)
	{
		line = readline("MINISHELL : ");
		if (line != NULL)
		{
			lst_cmd = parsing(line, env);
			info->exec->cmds = lst_cmd;
			// debug
			//debug_print_lst_cmd(lst_cmd);
			
			// execute
			execute(info, env);

			//debug_print_lst_cmd(lst_cmd); // 구조체에 들어간 토큰리스트를 출력함
			ft_free_cmdlst(lst_cmd); // cmd구조체와 그 안의 토큰 리스트 전부 할당해제함.
			free(line);
		}
		else
			ft_error_exit(0, "exit");
	}
}

void	init_info(t_info *info, t_envlst *env)
{
	info->exec = ft_calloc(1, sizeof(t_exec));
	if (info->exec == NULL)
	{
		ft_putendl_fd("init_error", 2);
		exit(1);
	}
	info->exec->env = env;
	info->cur_path = getcwd(NULL, 0);
	if (info->cur_path == NULL)
		perror("initiating minishell.. error in getcwd..");
	else
		ft_setenv(env, "PWD", info->cur_path, TRUE);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_envlst	*env;
	t_info		info;

	env = NULL;
	argument_error_check(argc);
	init_envp(envp, &env);
	init_info(&info, env);
	set_sigtermset(IN_MINISHELL_NO_CHILD);
	main_loop(&info, env, envp);
	return (0);
}
