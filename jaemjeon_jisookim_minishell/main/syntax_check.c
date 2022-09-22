/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:52:30 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 22:38:57 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_syntax_single_token(t_info* info, t_token *tok)
{
	printf("(debug) tok->string_value : %s\n", tok->string_value);
	if (tok->type & WORD)
		return (0);
	else if (tok->type & REDIRECT)
	{
		info->exit_str = ft_strdup("newline");
		return (1);
	}
	else if (tok->type & PIPE)
	{
		info->exit_str = ft_strdup("|");
		return (1);
	}
	return (0);
}

int	check_syntax_multiple_token(t_info* info, t_token *front)
{
	t_token *back;
	back = front->next;
	if (front->type & REDIRECT)
	{	
		if (syntax_check_redirect(info, back));
			reutrn (1);
	}
	else if (front->type & PIPE)
	{
		if (syntax_check_pipe(info, back))
			return (1);
	}
	else if (front->type & EXPANDER)
	{
		if (syntax_check_expander(info, back))
			reutrn (1);
	}
	return (0);
}

int	syntax_check_redirect(t_info *info, t_token *back)
{
	char	*type;
	
	if (back->type & WORD)
		return (0);
	else if (back->type & PIPE)
	{
		info->exit_str = ft_strdup("|");
		return (1);
	}
	else if (back->type & REDIRECT)
	{
		if (back->type & REDIRECT)
			type = "<<";
		else if (back->type & READ)
			type = "<";
		else if (back->type & WRITE)
			type = ">";
		else if (back->type & WRITE_APPEND)
			type = ">>";
		info->exit_str = ft_strdup(type);
		return (2);
	}
}

int	syntax_check_pipe(t_info *info, t_token *back)
{
	if (back->type & PIPE)
	{
		info->exit_str = ft_strdup("||");
		return (1);
	}
	return (0);
}

int	syntax_check_expander(t_info *info, t_token *back)
{
	return (1);
}

void	print_syntax_err(t_info *info)
{
	ft_putstr_fd("minishell : syntax error near unexpected token `", 2);
	ft_putstr_fd(info->exit_str, 2);
	ft_putstr_fd("'\n", 2);
	return (0);
}