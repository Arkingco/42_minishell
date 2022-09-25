/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:16:21 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 20:14:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	__skip_envkey(char **pointer)
{
	while (**pointer != '$' && **pointer != '\0' && **pointer != '\"' && \
		**pointer != '\'' && !ft_is_ifs(*pointer))
		(*pointer)++;
}

int	__is_to_remove_dollar(t_token *cur_token, char *context)
{
	if ((*context == '\0') && (cur_token->next != NULL) && \
			(cur_token->type & RIGHT_JOIN) && (cur_token->next->type & QUOTE))
		return (TRUE);
	else
		return (FALSE);
}

void	__skip_only_quote_and_letter(char **pointer)
{
	while (**pointer != '\0' && **pointer != '$' && \
			ft_is_ifs(*pointer) == FALSE)
		(*pointer)++;
}

t_token	*__word_split(t_token *token)
{
	char	*string_value;
	t_token	*splited_lst;
	t_token	*new_token;

	splited_lst = NULL;
	string_value = token->string_value;
	if (is_ifs_word(string_value))
		splited_lst = \
			ft_make_newtoken(token->type & ~(LEFT_JOIN | RIGHT_JOIN), "");
	else
	{
		while (*string_value != '\0')
		{
			new_token = ft_strtok_token(token->type, &string_value);
			if (new_token == NULL)
				break ;
			ft_token_lstadd_back(&splited_lst, new_token);
		}
	}
	return (splited_lst);
}
