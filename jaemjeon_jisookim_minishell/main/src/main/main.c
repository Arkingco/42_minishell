/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/12 03:12:27 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	main_loop(t_envlst *env, char **envp)
{
	char	*line;
	t_token	*lst_token;
	t_cmd	*lst_cmd;

	while (1)
	{
		line = readline("MINISHELL : ");
		add_history(line);
		if (line != NULL)
		{
			// quote의 짝이 맞는지에 대한 에러검사를 tokenize를 들어가기 전에 합니다.
			lst_token = tokenize(line); // word, quote, redirect, pipe로 토큰을 나눔.
			expander(&lst_token, env); // 확장하고 필요없는 토큰을 지우고 word_split을 하고 양쪽 문맥을 보고 token을 join시킴
			remove_trash_token(&lst_token);
			quote_remove(&lst_token);
			word_split(&lst_token);
			word_join(&lst_token);
			// debug_print_lst_token(lst_token);
			combine_redirect_filename(lst_token); // 리다이렉션바로 뒤의 word토큰을 합침
			lst_cmd = token_to_cmd(lst_token); // 토큰을 cmd구조체에 넣음

			// execute
			execute(lst_cmd, env);

			// debug_print_lst_cmd(lst_cmd); // 구조체에 들어간 토큰리스트를 출력함
			ft_free_cmdlst(lst_cmd); // cmd구조체와 그 안의 토큰 리스트 전부 할당해제함.
			free(line);
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
	// built_in_env(env);
	main_loop(env, envp);
	return (0);
}
