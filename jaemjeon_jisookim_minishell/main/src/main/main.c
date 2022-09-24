/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:05:11 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 09:41:16 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_errno;

int	is_error_token(t_token *suspect_token)
{
	if (suspect_token->next == NULL)
	{
		if (suspect_token->type & REDIRECT)
			return (TRUE);
		else if (suspect_token->type & PIPE)
			return (TRUE);
		else
			return (FALSE);
	}
	if (suspect_token->prev == NULL)
	{
		if (suspect_token->type & PIPE)
			return (TRUE);
		else
			return (FALSE);
	}
	else
	{
		if (suspect_token->prev->type & REDIRECT)
		{
			if (!(suspect_token->type & WORD))
				return (TRUE);
		}
		else if (suspect_token->prev->type & PIPE)
		{
			if (suspect_token->type & PIPE)
				return (TRUE);
		}
	}
	return (FALSE);
}

int	check_syntax_grammar(t_token *lst_token)
{
	while (lst_token != NULL)
	{
		if (is_error_token(lst_token))
		{
			if (lst_token->next == NULL && lst_token->type & REDIRECT)
				process_errno(258, "newline", SYNTAX_ERR);
			else if (lst_token->prev == NULL && lst_token->type & PIPE)
				process_errno(258, "|", SYNTAX_ERR);
			else
			{
				if (lst_token->type & PIPE)
					process_errno(258, "|", SYNTAX_ERR);
				else if (lst_token->type & WRITE)
					process_errno(258, ">", SYNTAX_ERR);
				else if (lst_token->type & WRITE_APPEND)
					process_errno(258, ">>", SYNTAX_ERR);
				else if (lst_token->type & READ)
					process_errno(258, "<", SYNTAX_ERR);
				else if (lst_token->type & HEREDOC)
					process_errno(258, "<<", SYNTAX_ERR);
			}
			return (TRUE);
		}
		lst_token = lst_token->next;
	}
	return (FALSE);
}

t_cmd	*parsing(char *line, t_working_info *info)
{
	t_token	*lst_token;
	t_cmd	*lst_cmd;

	// quote의 짝이 맞는지에 대한 에러검사를 tokenize를 들어가기 전에 합니다.
	lst_token = tokenize(line);		 // word, quote, redirect, pipe로 토큰을 나눔.
	if (check_syntax_grammar(lst_token) == TRUE)
	{
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
		line = readline("MINISHELL : ");
		add_history(line);
		if (line != NULL)
		{
			g_errno = 0;
			if (check_syntax_quote(line) == FALSE)
			{
				process_errno(258, "QUOTE", SYNTAX_ERR);
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
