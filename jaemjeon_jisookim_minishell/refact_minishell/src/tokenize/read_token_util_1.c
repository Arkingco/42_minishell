/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token_util_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:57:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/25 15:40:22 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	move_index_to_pair_quote(t_token *token, char *line, int *index)
{
	(*index)++;
	if (token->type & DQUOTE)
	{
		while (line[*index] != '\"')
			(*index)++;
	}
	else
	{
		while (line[*index] != '\'')
			(*index)++;
	}
	(*index)++;
}

void	move_index_next_to_end_of_word(char *line, int *index)
{
	(*index)++;
	while (!(line[*index] == '$' || line[*index] == '\'' || line[*index] == '\"' \
	|| ft_is_ifs(&line[*index]) || line[*index] == '\0' || line[*index] == '|'))
		(*index)++;
}

void	set_flag_joined(t_token *token, char *line, int start_idx, int end_idx)
{
	if (is_leftjoined(line, start_idx))
		token->type |= LEFT_JOIN;
	if (is_rightjoined(line, end_idx))
		token->type |= RIGHT_JOIN;
}

int	is_leftjoined(char *line, int left_idx)
{
	char	prev_char;

	if (left_idx == 0)
		return (FALSE);
	prev_char = line[left_idx - 1];
	if (ft_is_ifs(&prev_char) || prev_char == '|' || prev_char == '<' || \
				prev_char == '>')
		return (FALSE);
	else
		return (TRUE);
}

int	is_rightjoined(char *line, int right_idx)
{
	char	next_char;

	next_char = line[right_idx + 1];
	if (ft_is_ifs(&next_char) || next_char == '|' || next_char == '<' || \
				next_char == '>' || next_char == '\0')
		return (FALSE);
	else
		return (TRUE);
}
