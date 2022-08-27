/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:03:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/27 16:36:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
# include <sys/wait.h>


t_token	*make_quote_removed_token(unsigned int type, char *string_value)
{
	char			*string_value_quote_removed;
	unsigned int	new_type;
	t_token			*new_token;

	string_value_quote_removed = ft_strdup(string_value + 1);
	if (string_value_quote_removed == NULL)
		ft_error_exit(1, "malloc failed in make_quote_removed_token");
	string_value_quote_removed[ft_strlen(string_value_quote_removed) - 1] = '\0';
	new_type = (type & WORD_JOIN) | WORD | PURE_WORD;
	if (type & EXPANDER)
		new_type |= EXPANDED;
	new_token = ft_make_newtoken(new_type, string_value_quote_removed);
	// free(string_value_quote_removed);
	return (new_token);
}

t_token	*make_ifs_splited_tokenlst(unsigned int type, char *string_value)
{
	t_token	*splited_lst;
	char	*start_point;
	int		index;
	int		word_len;
	char	*new_string;

	index = 0;
	splited_lst = NULL;
	while (string_value[index] != '\0')
	{
		word_len = 0;
		ft_skip_ifs2(string_value, &index);
		start_point = &string_value[index];
		while (ft_is_ifs(&string_value[word_len]) == FALSE && string_value[word_len] != '\0')
			word_len++;
		new_string = ft_substr(string_value, index, word_len);
		if (new_string == NULL)
			ft_error_exit(1, "malloc failed in make_ifs_splited_tokenlst");
		ft_addtoken(&splited_lst, WORD | PURE_WORD | EXPANDED, new_string);
		free(new_string);
		index += word_len;
	}
	return (splited_lst);
}

char	*change_env_to_value(t_token *to_expand, t_envlst *env)
{
	char	*expanded_value;
	char	*to_expand_value;
	char	*tmp_value;
	char	*to_add;
	int		read_len;

	to_expand_value = to_expand->string_value;
	expanded_value = ft_strdup("");
	if (expanded_value == NULL)
		ft_error_exit(1, "malloc failed in change_env_to_value");
	while (*to_expand_value != '\0')
	{
		if (*to_expand_value == '$')
		{
			read_len = 1;
			if (*(to_expand_value + 1) == '\0' && to_expand->next != NULL && to_expand->next->type & QUOTE)
			{
				*to_expand_value = '\0';
				break ;
			}
			while (to_expand_value[read_len] != '\0' && to_expand_value[read_len] != '$' && to_expand_value[read_len] != '\"')
				read_len++;
			to_add = ft_substr(to_expand_value, 1, read_len - 1);
			tmp_value = ft_strjoin(expanded_value, ft_getenv(env, to_add));
		}
		else
		{
			read_len = 0;
			while (to_expand_value[read_len] != '\0' && to_expand_value[read_len] != '$')
				read_len++;
			to_add = ft_substr(to_expand_value, 0, read_len);
			tmp_value = ft_strjoin(expanded_value, to_add);
		}
		free(expanded_value);
		free(to_add);
		expanded_value = tmp_value;
		to_expand_value += read_len;
	}
	return (expanded_value);
}

t_token	*expand_env_to_value(t_token *to_expand, t_envlst *env)
{
	t_token	*expanded_lst;
	char	*expanded_value;

	expanded_value = change_env_to_value(to_expand, env);
	if (to_expand->type & DQUOTE)
	{
		expanded_lst =
			make_quote_removed_token(to_expand->type, expanded_value);
	}
	else
	{
		expanded_lst =
			make_ifs_splited_tokenlst(to_expand->type, expanded_value);
		if (ft_strlen(expanded_value) == 0)
			expanded_lst->type |= (LEFT_JOIN | RIGHT_JOIN);
		else
		{
			if (ft_is_ifs(&expanded_value[0]) == FALSE)
				expanded_lst->type |= LEFT_JOIN;
			if (ft_is_ifs(&expanded_value[ft_strlen(expanded_value) - 1]) == FALSE)
				(ft_token_lstlast(expanded_lst))->type |= RIGHT_JOIN;
		}
	}
	free(expanded_value);
	return (expanded_lst);
}

void	expand_pidenv(t_token *token_lst)
{
	char	*string_value;
	int		index;

	index = 0;
	string_value = token_lst->string_value;
	while (string_value[index] != '\0' && string_value[index + 1] != '\0')
	{
		if (ft_strncmp(&string_value[index], "$$", 2) == 0)
		{
			ft_memcpy(&string_value[index], &string_value[index + 2], \
										ft_strlen(string_value) - index - 1);
			continue ;
		}
		index++;
	}
}

void	expand(t_token **token_lst, t_envlst *env)
{
	t_token	*cur_token;
	t_token	*expanded_lst;

	cur_token = *token_lst;
	expand_pidenv(*token_lst);
	expanded_lst = expand_env_to_value(cur_token, env);
	ft_insert_token(*token_lst, expanded_lst);
	// ft_deltoken(token_lst);
	if (!((*token_lst)->type & QUOTE))
		(*token_lst)->string_value[0] = '\0';
	else
		ft_deltoken(token_lst);
}

t_token	*expander(t_token *token_lst, t_envlst *env)
{
	t_token	*cur_token;
	t_token	*prev_token;

	cur_token = token_lst;
	while (cur_token != NULL)
	{
		if (token_lst->type & EXPANDER)
			expand(&cur_token, env);
		prev_token = cur_token;
		cur_token = cur_token->next;
	}
	cur_token = ft_token_lst_first(prev_token);
	token_lst = cur_token;
	// 아래는 pure_word중 빈 문자열을 싹 지우고 첫 노드를 반환하는 코드
	while (cur_token != NULL)
	{
		if (!(cur_token->type & QUOTE) && (cur_token->string_value[0] == '\0'))
		{
			if (cur_token->prev != NULL)
			{
				cur_token = cur_token->prev;
				ft_deltoken(&cur_token->next);
			}
			else if (cur_token->next != NULL)
			{
				cur_token = cur_token->next;
				token_lst = cur_token;
				ft_deltoken(&cur_token->prev);
				continue ;
			}
			else
			{
				ft_deltoken(&cur_token);
				return (NULL);
			}
		}
		cur_token = cur_token->next;
	}
	return (token_lst);
}