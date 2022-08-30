/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:03:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/30 22:05:36 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
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
	free(string_value_quote_removed);
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

void	change_env_to_value(t_token *to_expand, t_envlst *env)
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
	free(to_expand->string_value);
	to_expand->string_value = expanded_value;
}

void	set_wordjoin_flags(t_token *to_expand)
{
	int	len_string_value;

	len_string_value = ft_strlen(to_expand->string_value);
	if (len_string_value == 0)
	{
		to_expand->type |= (LEFT_JOIN | RIGHT_JOIN);
		return ;
	}
	else
	{
		if (ft_is_ifs(&to_expand->string_value[0]) == TRUE)
			to_expand->type |= LEFT_JOIN;
		else if (ft_is_ifs(&to_expand->string_value[len_string_value - 1]) == TRUE)
			to_expand->type |= RIGHT_JOIN;
	}
}

void	expand_env_to_value(t_token *to_expand, t_envlst *env)
{
	char	*expanded_value;

	change_env_to_value(to_expand, env);
	set_wordjoin_flags(to_expand);
}

// t_token	*expand_env_to_value(t_token *to_expand, t_envlst *env)
// {
// 	t_token	*expanded_lst;
// 	char	*expanded_value;

// 	expanded_value = change_env_to_value(to_expand, env);
// 	if (to_expand->type & DQUOTE)
// 	{
// 		expanded_lst =
// 			make_quote_removed_token(to_expand->type, expanded_value);
// 	}
// 	else
// 	{
// 		expanded_lst =
// 			make_ifs_splited_tokenlst(to_expand->type, expanded_value);
// 		if (ft_strlen(expanded_value) == 0)
// 			expanded_lst->type |= (LEFT_JOIN | RIGHT_JOIN);
// 		else
// 		{
// 			if (ft_is_ifs(&expanded_value[0]) == FALSE)
// 				expanded_lst->type |= LEFT_JOIN;
// 			if (ft_is_ifs(&expanded_value[ft_strlen(expanded_value) - 1]) == FALSE)
// 				(ft_token_lstlast(expanded_lst))->type |= RIGHT_JOIN;
// 		}
// 	}
// 	free(expanded_value);
// 	return (expanded_lst);
// }

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
	// expanded_lst = expand_env_to_value(cur_token, env);
	ft_insert_token(*token_lst, expanded_lst);
	// ft_deltoken(token_lst);
	if (!((*token_lst)->type & QUOTE))
		(*token_lst)->string_value[0] = '\0';
	else
	{
		*token_lst = (*token_lst)->next;
		ft_deltoken(&(*token_lst)->prev);
	}
}
*/












void	expand_pidenv(t_token *token)
{
	char	*pid_suspect;
	char	*tmp_string;

	pid_suspect = token->string_value;
	while (1)
	{
		pid_suspect = ft_strchr(pid_suspect, '$');
		if (pid_suspect == NULL)
			break ;
		if (ft_strncmp(pid_suspect, "$$", 2) != 0)
		{
			pid_suspect++;
			continue ;
		}
		else
		{
			ft_memmove(pid_suspect, pid_suspect + 2, ft_strlen(pid_suspect) + 1);
			token->type |= EXPANDED;
		}
	}
	tmp_string = ft_strdup(token->string_value);
	free(token->string_value);
	token->string_value = tmp_string;
}

char	*raise_buffer(char *prev, int raise_size)
{
	char	*raised_buffer;

	raised_buffer = (char *)ft_calloc(1, ft_strlen(prev) + raise_size + 1);
	ft_strlcpy(raised_buffer, prev, ft_strlen(prev) + 1);
	free(prev);
	return (raised_buffer);
}

void	__skip_envkey(char **pointer)
{
	while (**pointer != '$' && **pointer != '\0' && **pointer != '\"' && \
		**pointer != '\'' && !ft_is_ifs(*pointer) )
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

char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env)
{
	char	*expanded_string;
	char	*env_key;
	char	*env_value;

	__skip_envkey(envkey_end);
	if (doller_p + 1 == *envkey_end)
	{
		expanded_string = ft_strdup("$");
		return (expanded_string);
	}
	else
	{
		env_key = ft_substr(doller_p, 1, *envkey_end - doller_p - 1);
		env_value = ft_getenv(env, env_key);
		if (env_value != NULL)
			expanded_string = ft_strdup(env_value);
		else
			expanded_string = ft_strdup("");
		free(env_key);
		return (expanded_string);
	}
}

char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*expanded_string;
	char	*env_key;

	cpy_start = *context;
	cpy_end = cpy_start + 1;
	if (__is_to_remove_dollar(token, cpy_end))
		expanded_string = ft_strdup("");
	else
		expanded_string = __get_envvalue(cpy_start, &cpy_end, env);
	*context = cpy_end;
	return (expanded_string);
}

char	*cpy_ifs_string(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context;
	cpy_end = cpy_start;
	while (ft_is_ifs(cpy_end))
		cpy_end++;
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start);
	*context = cpy_end;
	return (copied_string);
}

void	__skip_only_quote_and_letter(char **pointer)
{
	while (**pointer != '\0' && **pointer != '$' && \
		ft_is_ifs(*pointer) == FALSE)
		(*pointer)++;
}

void	*cpy_none_expander(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context;
	cpy_end = cpy_start;
	__skip_only_quote_and_letter(&cpy_end);
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start);
	*context = cpy_end;
	return (copied_string);
}

void	expand_env(t_token *token, t_envlst *env)
{
	char	*cpy_start;
	char	*result;
	char	*copied_string;
	char	*env_key;
	char	*env_value;

	cpy_start = token->string_value;
	result = ft_strdup("");
	while (*cpy_start != '\0')
	{
		if (*cpy_start == '$')
			copied_string = expand_env_withdollar(token, env, &cpy_start);
		else if (*cpy_start == ' ')
			copied_string = cpy_ifs_string(&cpy_start);
		else
			copied_string = cpy_none_expander(&cpy_start);
		result = raise_buffer(result, ft_strlen(copied_string));
		ft_strlcat(result, copied_string, \
							ft_strlen(result) + ft_strlen(copied_string) + 1);
		free(copied_string);
	}
	free(token->string_value);
	token->string_value = result;
}

void remove_trash_token(t_token **token_lst)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & EXPANDER) && !(cur_token->type & EXPANDED) && \
			ft_strlen(cur_token->string_value) == 0)
		{
			if (cur_token->prev == NULL && cur_token->next == NULL)
			{
				ft_deltoken(token_lst);
				return ;
			}
			else if (cur_token->prev == NULL)
			{
				cur_token = (*token_lst)->next;
				ft_deltoken(token_lst);
				*token_lst = cur_token;
			}
			else if (cur_token->next == NULL)
			{
				ft_deltoken(&cur_token);
				return ;
			}
			else
			{
				cur_token = cur_token->next;
				ft_deltoken(&cur_token->prev);
			}
		}
		else
			cur_token = cur_token->next;
	}
}

int	is_ifs_word(char *string_value)
{
	while (ft_is_ifs(string_value) == TRUE && *string_value != '\0')
		string_value++;
	if (*string_value == '\0')
		return (TRUE);
	else
		return (FALSE);
}

void	word_split(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*splited_lst;
	t_token	*new_token;
	char	*string_value;

	cur_token = *token_lst;
	splited_lst = NULL;
	while (cur_token != NULL)
	{
		if ((cur_token->type & WORD) && !(cur_token->type & QUOTE) && ft_has_ifs(cur_token->string_value))
		{
			string_value = cur_token->string_value;
			if (is_ifs_word(string_value))
				splited_lst = ft_make_newtoken(cur_token->type & ~(LEFT_JOIN | RIGHT_JOIN), "");
			else
			{
				while (*string_value != '\0')
				{
					new_token = ft_strtok_token(cur_token->type, &string_value);
					if (new_token == NULL)
						break;
					ft_token_lstadd_back(&splited_lst, new_token);
				}
			}
			ft_insert_token(cur_token, splited_lst);
			if (cur_token->next == NULL && cur_token->prev == NULL)
				ft_deltoken(token_lst);
			else if (cur_token->next == NULL)
				ft_deltoken(&cur_token);
			else if (cur_token->prev == NULL)
			{
				cur_token = cur_token->next;
				ft_deltoken(token_lst);
			}
			else
			{
				cur_token = cur_token->next;
				ft_deltoken(&cur_token->prev);
			}
			continue ;
		}
		cur_token = cur_token->next;
	}
}

void	quote_remove(t_token **token_lst)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if (cur_token->type & QUOTE)
		{
			ft_memmove(cur_token->string_value, cur_token->string_value + 1, ft_strlen(cur_token->string_value));
			cur_token->string_value[ft_strlen(cur_token->string_value) - 1] = '\0';
		}
		cur_token = cur_token->next;
	}
}

void	word_join(t_token **token_lst)
{
	t_token	*cur_token;
	char	*joined_string;

	cur_token = *token_lst;
	while (cur_token != NULL && cur_token->next != NULL)
	{
		if (cur_token->type & RIGHT_JOIN && cur_token->next->type & LEFT_JOIN)
		{
			joined_string = ft_strjoin(cur_token->string_value, cur_token->next->string_value);
			free(cur_token->string_value);
			cur_token->string_value = joined_string;
			if ((cur_token->next->type & RIGHT_JOIN) == FALSE)
				cur_token->type &= ~RIGHT_JOIN;
			ft_deltoken(&(cur_token->next));
		}
		cur_token = cur_token->next;
	}
}

void	expander(t_token **token_lst, t_envlst *env)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & WORD) && !(cur_token->type & SQUOTE))
		{
			expand_pidenv(cur_token);
			expand_env(cur_token, env);
		}
		if (cur_token->next == NULL) // 지울수도  있음
			break ;
		else
			cur_token = cur_token->next;
	}
	remove_trash_token(token_lst);
	quote_remove(token_lst);
	word_split(token_lst);
	word_join(token_lst);
}
