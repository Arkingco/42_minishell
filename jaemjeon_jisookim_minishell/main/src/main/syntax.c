/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:40:48 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 19:57:29 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_token_type(t_token *token)
{
	t_token *tok;

	tok = token;
	if (tok->string_value != NULL)
	{
		if (tok->type & EXPANDER)
			return (EXPANDER);
		else if (tok->type & REDIRECT)
			return (REDIRECT);
		else
			return (PIPE);
	}
	else
		return (WORD);
}

int	check_syntax_token(t_token *tok, int *tok_types)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (tok)
	{
		j = i + 1;
		flag = check_front_and_back_tokens(tok_types[i], tok_types[j]);
		if (flag)
			return (flag);
		i++;
		tok = tok->next;
	}
	return (flag);
}

int	check_front_and_back_tokens(int front, int back)
{
	if (front & WORD)
		return (0);
	else if (front & REDIRECT)
	{
		if (back & REDIRECT || back & PIPE || back == NULL)
			return (1);
	}
	else if (front & PIPE)
	{
		if (back & PIPE || back == NULL)
			return (1);
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

void	check_syntax(t_token *lst_token)
{
	int		i;
	t_token *tok;
	int		*tok_types;

	tok = lst_token;
	i = count_token(tok);
	if (i == 0)
		return ;
	tok_types = safe_calloc(i, sizeof(int));
	i = 0;
	while (tok)
	{
		tok_types[i] = check_token_type(tok);
		i++;
		tok = tok->next;
	}
	if (check_syntax_token(tok, tok_types))
	{
		free(tok_types);
		ft_putstr_fd("syntax error near unexpected token`%s'\n", tok->string_value);
		exit (1);
	}
	free(tok_types);
	return (0);
}

