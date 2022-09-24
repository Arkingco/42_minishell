/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_read_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:59:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 19:53:54 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token		*read_in_quote(char *line, int *index)
{
	t_token *new_token;
	int		start_idx;

	start_idx = *index;
	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in read_token");
	if (line[start_idx] == '\'')
		new_token->type |= (WORD | SQUOTE);
	else if (line[start_idx] == '\"')
		new_token->type |= (WORD | DQUOTE);
	move_index_to_pair_quote(new_token, line, index);
	new_token->string_value = ft_substr(line, start_idx, *index - start_idx);
	if (new_token->string_value == NULL)
		ft_error_exit(1, "malloc failed in ft_substr in read_token");
	set_flag_joined(new_token, line, start_idx, *index - 1);
	if (ft_strchr(new_token->string_value, '$') && new_token->type & DQUOTE)
		new_token->type |= EXPANDER;
	return (new_token);
}

t_token		*read_in_redirect(char *line, int *index)
{
	t_token	*new_token;

	if ((new_token = (t_token *)ft_calloc(1, sizeof(t_token))) == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in read_token");
	if (line[*index] == '<' && line[*index + 1] == '<')
	{
		(*index) += 2;
		new_token->type |= (REDIRECT | HEREDOC);
	}
	else if (line[*index] == '>' && line[*index + 1] == '>')
	{
		(*index) += 2;
		new_token->type |= (REDIRECT | WRITE_APPEND);
	}
	else if (line[*index] == '<' && line[*index + 1] != '<')
	{
		(*index) += 1;
		new_token->type |= (REDIRECT | READ);
	}
	else if (line[*index] == '>' && line[*index + 1] != '>')
	{
		(*index) += 1;
		new_token->type |= (REDIRECT | WRITE);
	}
	return (new_token);
}

t_token		*read_in_pipe(char *line, int *index)
{
	t_token	*new_token;

	(void)&line;
	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in read_token");
	new_token->type |= PIPE;
	(*index)++;
	return (new_token);
}

t_token		*read_in_expander(char *line, int *index)
{
	t_token	*new_token;
	int		start_idx;

	start_idx = *index;
	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in read_token");
	new_token->type |= (WORD | EXPANDER);
	move_index_next_to_end_of_word(line, index);
	new_token->string_value = ft_substr(line, start_idx, *index - start_idx);
	if (new_token->string_value == NULL)
		ft_error_exit(1, "malloc failed in ft_substr in read_token");
	set_flag_joined(new_token, line, start_idx, *index - 1);
	return (new_token);
}

t_token		*read_in_pureword(char *line, int *index)
{
	t_token	*new_token;
	int		start_idx;

	start_idx = *index;
	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		ft_error_exit(1, "malloc failed in ft_calloc in read_token");
	new_token->type |= (WORD | PURE_WORD);
	move_index_next_to_end_of_word(line, index);
	new_token->string_value = ft_substr(line, start_idx, *index - start_idx);
	if (new_token->string_value == NULL)
		ft_error_exit(1, "malloc failed in ft_substr in read_token");
	set_flag_joined(new_token, line, start_idx, *index - 1);
	if (ft_strchr(new_token->string_value, '$'))
		new_token->type |= EXPANDER;
	return (new_token);
}
