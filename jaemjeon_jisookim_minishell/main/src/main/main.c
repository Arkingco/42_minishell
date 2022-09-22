/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/23 02:18:20 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_errno;

int	check_syntax_grammar(t_token *lst_token)
{
	t_token	*cur_token;
	t_token	*next_token;

	cur_token = lst_token;
	next_token = cur_token->next;
	while (next_token != NULL)
	{
		if (cur_token->type & REDIRECT)
		{
			if (!(next_token->type & WORD))
				return (FALSE);
		}
		else if (cur_token->type & PIPE)
		{
			if ((next_token->type & PIPE))
				return (FALSE);
		}
		cur_token = next_token;
		next_token = next_token->next;
	}
	if (!(cur_token->type & WORD))
		return (FALSE);
	return (TRUE);
}

t_cmd	*parsing(char *line, t_working_info *info)
{
	t_token	*lst_token;
	t_cmd	*lst_cmd;

	// quote의 짝이 맞는지에 대한 에러검사를 tokenize를 들어가기 전에 합니다.
	lst_token = tokenize(line);		 // word, quote, redirect, pipe로 토큰을 나눔.
	if (check_syntax_grammar(lst_token) == FALSE)
	{
		ft_putendl_fd("syntax error near unexpected token", 2);
		ft_free_tokenlst(lst_token);
		return (NULL);
	}
	expander(&lst_token, info->env); // 확장하고 필요없는 토큰을 지우고 word_split을 하고 양쪽 문맥을 보고 token을 join시킴
	remove_trash_token(&lst_token);
	quote_remove(&lst_token);
	word_split(&lst_token);
	word_join(&lst_token);
	combine_redirect_filename(lst_token); // 리다이렉션바로 뒤의 word토큰을 합침
	lst_cmd = token_to_cmd(lst_token);	  // 토큰을 cmd구조체에 넣음
	return (lst_cmd);
}

int	check_syntax_quote(char *line)
{
	while (*line != '\0')
	{
		if (*line == '\'')
		{
			line = ft_strchr(line + 1, '\'');
			if (line == NULL)
				return (FALSE);
		}
		else if (*line == '\"')
		{
			line = ft_strchr(line + 1, '\"');
			if (line == NULL)
				return (FALSE);
		}
		line++;
	}
	return (TRUE);
}

void	main_loop(t_working_info *info)
{
	char		*line;
	t_cmd		*lst_cmd;

	while (1)
	{
		g_errno = 24;
		line = readline("MINISHELL : ");
		add_history(line);
		if (line != NULL)
		{
			if (check_syntax_quote(line) == FALSE)
			{
				printf("ㅇㅡㅇ악\n");
				free(line);
				continue ;
			}
			info->cmd = parsing(line, info);
			// debug_print_lst_cmd(info->cmd);
			if (info->cmd != NULL)
			{
				execute(info);
				ft_free_cmdlst(info->cmd); // cmd구조체와 그 안의 토큰 리스트 전부 할당해제함.
			}
			free(line);
		}
		else
			ft_error_exit(0, "exit");
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_working_info	info;

	g_errno = 0;
	argument_error_check(argc);
	init_envp(&info, envp);
	init_cur_path(&info);
	sigtermset(MINISHELL_NO_CHILD);
	main_loop(&info);
	return (0);
}
