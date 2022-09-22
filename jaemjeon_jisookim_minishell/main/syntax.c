/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:40:48 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 22:43:22 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int	check_syntax_token(t_info *info, t_token *tok, int *tok_types)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (tok)
	{
		j = i + 1;
		flag = check_front_and_back_tokens(info, tok, tok_types[i], tok_types[j]);
		if (flag)
			return (flag);
		i++;
		tok = tok->next;
	}
	return (flag);
}

int	check_front_and_back_tokens(t_info *info, t_token *tok, int front, int back)
{
	if (front & WORD)
	{
		printf("word!");
		return (0);
	}
	else if (front & REDIRECT)
	{
		if (back & REDIRECT || back & PIPE || !back)
		{
			set_err_string(info, tok, back);
			return (1);
		}
	}
	else if (front & PIPE)
	{
		if (back & PIPE || !back)
		{
			set_err_string(info, tok, back);
			return (1);
		}
	}
	else if (front & EXPANDER)
	{
		;
	}
	return (0);
}


int	count_token(t_token *token)
{
	t_token	*tok;
	int		count;
	
	tok = token;
	count = 0;
	while (tok)
	{
		count++;
		tok = tok->next;
	}
	return (count);
}

void	check_syntax(t_info *info, t_token *lst_token)
{
	int		i;
	t_token *tok;
	int		*tok_types;

	tok = lst_token;
	info->exit_flag = 0;
	i = count_token(tok);
	if (i == 0)
		return ; // 아무것도 들어가지 않을 때
	else if (i == 1)
		info->exit_flag = check_syntax_single_token(info, tok);
	else
		info->exit_flag = check_syntax_multiple_token(info, tok);
	if (info->exit_flag)
			return ;
}

	// tok_types = safe_calloc(i, sizeof(int));
	// i = 0;
	// while (tok)
	// {
	// 	tok_types[i] = check_token_type(tok);
	// 	i++;
	// 	tok = tok->next;
	// }
	
	// if (check_syntax_token(info, tok, tok_types))
	// {
	// 	free(tok_types);
	// 	info->exit_flag = 1;
	// }
	// free(tok_types);
