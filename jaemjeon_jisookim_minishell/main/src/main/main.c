/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 21:48:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_errno;

t_cmd	*parsing(char *line, t_working_info *info)
{
	t_token	*lst_token;
	t_cmd	*lst_cmd;

	lst_token = tokenize(line);
	if (check_syntax_grammar(lst_token) == TRUE)
	{
		ft_free_tokenlst(lst_token);
		return (NULL);
	}
	expander(&lst_token, info->env);
	remove_trash_token(&lst_token);
	quote_remove(&lst_token);
	word_split(&lst_token);
	word_join(&lst_token);
	combine_redirect_filename(lst_token);
	lst_cmd = token_to_cmd(lst_token);
	return (lst_cmd);
}

void	main_loop(t_working_info *info)
{
	char		*line;

	while (1)
	{
		line = readline("minishell-0.1$ ");
		add_history(line);
		if (line != NULL)
		{
			if (do_check_syntax_quote(line))
				continue ;
			info->cmd = parsing(line, info);
			if (info->cmd != NULL)
			{
				g_errno = 0;
				execute(info);
				ft_free_cmdlst(info->cmd);
			}
			free(line);
			line = 0;
		}
		else
		{
			system("leaks minishell");
			ft_error_exit(0, "exit");
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_working_info	info;

	(void)&argv;
	g_errno = 0;
	argument_error_check(argc);
	init_envp(&info, envp);
	init_cur_path(&info);
	sigtermset(MINISHELL_NO_CHILD);
	main_loop(&info);
	return (0);
}
