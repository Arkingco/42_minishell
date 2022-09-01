/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:03:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/31 14:55:21 by jaemjeon         ###   ########.fr       */
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
	// char	*tmp_string;

	pid_suspect = token->string_value;
	while (1)
	{
		pid_suspect = ft_strchr(pid_suspect, '$'); // $로 시작하는 주소로 이동
		if (pid_suspect == NULL) // $가 없었던 문자였으면 그냥 while문 탈출
			break ;
		if (ft_strncmp(pid_suspect, "$$", 2) != 0) // $뒤에 $가 연속으로 나온게 아닌경우
		{
			pid_suspect++; // 다음 칸으로 이동
			continue ;
		}
		else // $$가 나와서 pid로 확장을 해야하는 경우
		{
			ft_memmove(pid_suspect, pid_suspect + 2, \
									ft_strlen(pid_suspect) + 1); // $$를 지워버림.
			token->type |= EXPANDED; // 그냥 지워진게 아니라 pid로 확장이 되었다는 맥락이니까 expanded flag도 박아줌
		}
	}
	// $$가 지워진 경우 할당된 메모리보다 사용하는 메모리가 적을테니까 재할당하여 메모리사용을 줄이는
	// 코드가 아래인데 사실 쉘에서 한줄을 실행하는데에 오랜 시간이 걸리지 않고 아래 과정으로 얻는
	// 메모리보다 free하고 새로할당해서 메모리 복사하는 과정의 비용이 더 비쌀것 같다는 생각이 듦.
	// tmp_string = ft_strdup(token->string_value);
	// free(token->string_value);
	// token->string_value = tmp_string;
}

/*
prev에 할당된 메모리에서 raise_size만큼 더 할당량을 늘리고 문자열을 복사해준다.
*/
char	*raise_buffer(char *prev, int raise_size)
{
	char	*raised_buffer;

	raised_buffer = (char *)ft_calloc(1, ft_strlen(prev) + raise_size + 1);
	ft_strlcpy(raised_buffer, prev, ft_strlen(prev) + 1); // 널문자까지의 사이즈를 넣어줘야함
	free(prev);
	return (raised_buffer);
}

/*
__get_envvlaue함수에서 envkey에 해당하는 만큼 포인터를 옮길때 사용함.
*/
void	__skip_envkey(char **pointer)
{
	while (**pointer != '$' && **pointer != '\0' && **pointer != '\"' && \
		**pointer != '\'' && !ft_is_ifs(*pointer))
		(*pointer)++;
}


/*
expand_env_withdollar에서 호출하는 함수로, 현재토큰의 마지막문자가 $이고 다음 토큰이 quote이면서
붙어있는 상태 (ex : $"HELLO") 인 경우에 앞의 $를 지워야하는데 그 상태인지 판단하는 함수
*/
int	__is_to_remove_dollar(t_token *cur_token, char *context)
{
	if ((*context == '\0') && (cur_token->next != NULL) && \
			(cur_token->type & RIGHT_JOIN) && (cur_token->next->type & QUOTE))
		return (TRUE);
	else
		return (FALSE);
}

/*
expand_env_withdollar에서 호출하는 함수로, $를 가르키는 포인터, envkey를 지나킬 포인터를 받는다.
1. 먼저 envkey의 다음칸으로 포인터를 옮겨준다.
2. 만약 dollar_p와 envkey_end가 1차이라면 실제론 $하나만 있었으니까 확장시키지 않고 그냥 $를 복사하여 반환
3. envkey를 찾았는데 (1) 해당되는 환경변수가 존재하는 경우 (2) 존재하지 않는경우 로 나뉜다.
3-(1). ft_getenv로 찾은 value값을 반환해줌
3-(2). 빈문자열을 복사하여 반환.
*/
char	*__get_envvalue(char *doller_p, char **envkey_end, t_envlst *env)
{
	char	*expanded_string;
	char	*env_key;
	char	*env_value;

	__skip_envkey(envkey_end); // 1
	if (doller_p + 1 == *envkey_end) // 2
	{
		expanded_string = ft_strdup("$");
		return (expanded_string);
	}
	else
	{
		env_key = ft_substr(doller_p, 1, *envkey_end - doller_p - 1);
		env_value = ft_getenv(env, env_key); // 3
		if (env_value != NULL)	// 3-(1)
			expanded_string = ft_strdup(env_value);
		else					// 3-(2)
			expanded_string = ft_strdup("");
		free(env_key);
		return (expanded_string);
	}
}

/*
$를 만났을때 확장하여 그 확장된 문자열을 반환해 주는 함수.
*/
char	*expand_env_withdollar(t_token *token, t_envlst *env, char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*expanded_string;
	char	*env_key;

	cpy_start = *context; // 현재 읽고 있는 토큰의 문자열 문맥을 받아옴
	cpy_end = cpy_start + 1;
	if (__is_to_remove_dollar(token, cpy_end)) //  지워야하는 $인지 판단
		expanded_string = ft_strdup(""); // 지워야하는거면 $를 빈문자열 반환
	else
	{
		expanded_string = __get_envvalue(cpy_start, &cpy_end, env); // 확장하여 반환
		token->type |= EXPANDED; // 확장된 토큰이라는 flag설정
	}
	*context = cpy_end; // 다음 $를 찾아 가야하니까 지금까지 읽은곳 다음 칸으로 문맥변경
	return (expanded_string);
}

/*
현재 포인터의 ifs부터 연속된 ifs들을 쭉 복사하여 반환함.
*/
char	*cpy_ifs_string(char **context)
{
	char	*cpy_start;
	char	*cpy_end;
	char	*copied_string;

	cpy_start = *context; // 문맥 받아옴
	cpy_end = cpy_start;
	while (ft_is_ifs(cpy_end)) // ifs가 아닌 문자가 나올때까지 계속 읽음
		cpy_end++;
	copied_string = ft_substr(cpy_start, 0, cpy_end - cpy_start); // ifs덩어리를 복사
	*context = cpy_end; // 문맥 교환
	return (copied_string); // 복사한 ifs덩어리 반환
}

/*
cpy_none_expander함수에서 호출하는 함수로, 다음 ifs, 널문자, $문자까지 포인터를 옮겨줌
*/
void	__skip_only_quote_and_letter(char **pointer)
{
	while (**pointer != '\0' && **pointer != '$' && \
		ft_is_ifs(*pointer) == FALSE)
		(*pointer)++;
}

/*
none_expander즉 일반 영문자나 따움표같은 문자들(널, ifs, $문자만나면 멈춤)을 쭉 복사해서 반환함.
*/
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

/*
현재토큰에서 확장을 해야하는 것들을 만나면 확장을 쭉해줌. 문자열덩어리, ifs덩어리, 확장된 덩어리들을
한 덩어리씩 모아서 계속 버퍼를 늘려주고 strlcat을 하여 늘려줌(strjoin을 계속하는 느낌)
*/
void	expand_env(t_token *token, t_envlst *env)
{
	char	*cpy_start;
	char	*result;
	char	*copied_string;
	char	*env_key;
	char	*env_value;

	cpy_start = token->string_value;
	result = ft_strdup(""); // 확장을 다한 문자열이 들어갈 공간
	while (*cpy_start != '\0')
	{
		if (*cpy_start == '$') // 확장가능성있는 문맥 발견
			copied_string = expand_env_withdollar(token, env, &cpy_start);
		else if (ft_is_ifs(cpy_start)) // ifs를 발견
			copied_string = cpy_ifs_string(&cpy_start);
		else // ifs도 아니고 확장가능성있는것도 아닌 일반 문자열또는 quote문자
			copied_string = cpy_none_expander(&cpy_start);
		result = raise_buffer(result, ft_strlen(copied_string)); // 확장된, 또는 복사해온 문자열길이만큼 버퍼를 키워줌.
		ft_strlcat(result, copied_string, \
							ft_strlen(result) + ft_strlen(copied_string) + 1); // 문자열 붙여줌
		free(copied_string);
	}
	free(token->string_value); // 확장된 문자열로 업데이트
	token->string_value = result;
}

/*
지워야하는 토큰을 지워줌.($로 시작했는데 확장되어서 널문자가 된게 아니라 뒤에 붙은 토큰이 quote여서 지워진 토큰을 실제로 지움)
*/
void	remove_trash_token(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*head_token;
	t_token	*to_del_token;

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & EXPANDER) && !(cur_token->type & EXPANDED) && \
			ft_strlen(cur_token->string_value) == 0)
		{
			if (cur_token->prev == NULL)
				head_token = cur_token->next;
			to_del_token = cur_token;
			ft_deltoken(&to_del_token);
		}
		cur_token = cur_token->next;
	}
	*token_lst = head_token;
}

/*
ifs로만 이루어진 문자열인지 판단
*/
int	is_ifs_word(char *string_value)
{
	while (ft_is_ifs(string_value) == TRUE && *string_value != '\0')
		string_value++;
	if (*string_value == '\0')
		return (TRUE);
	else
		return (FALSE);
}

/*
일단 word이고 quote밖에 있고 공백을 가지고 있다? -> 확장되서어 공백이 생긴것이므로 word_split을
해야하는 토큰으로 판단.
*/
int	is_to_word_split(t_token *token)
{
	return ((token->type & WORD) && !(token->type & QUOTE) && \
		ft_has_ifs(token->string_value));
}

/*
word_split함수에서 내부적으로 실행하는 함수.
word_split함수는 token_lst를 쭉 돌면서 split하는 함수라면 __word_split은 매개변수로 받은
token만을 split히여 그 split된 token_lst를 반환함. 하지만 매개변수로 받은 토큰을 지우지는 않음.
*/
t_token	*__word_split(t_token *token)
{
	char	*string_value;
	t_token	*splited_lst;
	t_token	*new_token;

	splited_lst = NULL;
	string_value = token->string_value;
	if (is_ifs_word(string_value))
		splited_lst = \
				ft_make_newtoken(token->type & ~(LEFT_JOIN | RIGHT_JOIN), ""); // 만약 ifs만으로 이루어진 토큰인 경우..
	else
	{
		while (*string_value != '\0')
		{
			// 토큰의 string_value를 쭉 훑으면서 ifs를 건너뛰고 하나씩 토큰화함. 물론 join_flag도 관리해줌
			new_token = ft_strtok_token(token->type, &string_value);
			if (new_token == NULL) // 더이상 토큰화할게 없음.
				break;
			ft_token_lstadd_back(&splited_lst, new_token);
		}
	}
	return (splited_lst); // split된 토큰 연결리스트 반환.
}

/*
토큰리스트를 쭉 돌면서 word_split해야하는 토큰들을 모두 토큰split해줌
*/
void	word_split(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*to_del_token;
	t_token	*splited_lst;
	t_token	*head_token; // 매개변수를 통해 리스트의 맨 처음포인터를 가르켜줄것임.

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if (is_to_word_split(cur_token)) // word_split할 토큰을 찾음
		{
			splited_lst = NULL;
			splited_lst = __word_split(cur_token); // split된 연결리스트 반환
			ft_insert_token(cur_token, splited_lst); // 현재다음으로 연결해주고,
			if (cur_token->prev == NULL) // 만약에 현재가 맨처음것이라면
				head_token = cur_token->next; // head_token을 다음것으로 바꿔줌.
			to_del_token = cur_token; // 이미 split해서 반영했으므로 현재것은 지워줌
			cur_token = cur_token->next;
			ft_deltoken(&to_del_token);
		}
		else
			cur_token = cur_token->next;
	}
	*token_lst = head_token; // 맨처음 연결리스트 반영
}


/*
quote로 둘러쌓인 토큰의 quote를 지움.
*/
void	quote_remove(t_token **token_lst)
{
	t_token	*cur_token;

	cur_token = *token_lst;
	while (cur_token != NULL)
	{
		if (cur_token->type & QUOTE)
		{
			ft_memmove(cur_token->string_value, cur_token->string_value + 1, \
										ft_strlen(cur_token->string_value));
			cur_token->string_value[ft_strlen(cur_token->string_value) - 1]\
																		 = '\0';
		}
		cur_token = cur_token->next;
	}
}

/*
word와 quote의 경우, 처음 토큰이 따로 되어있었으나 결국은 결과적으로 붙어있는 상태라면
(확장이후에 안붙어 있을 수 있으니 확장후를 봐야함) left_join & right_join 양쪽이 합치된다면 토큰을 합쳐줌

*/
void	word_join(t_token **token_lst)
{
	t_token	*cur_token;
	char	*joined_string;

	cur_token = *token_lst;
	while (cur_token != NULL && cur_token->next != NULL)
	{
		if (cur_token->type & RIGHT_JOIN && cur_token->next->type & LEFT_JOIN)
		{
			joined_string = \
			ft_strjoin(cur_token->string_value, cur_token->next->string_value);
			free(cur_token->string_value);
			cur_token->string_value = joined_string;
			if ((cur_token->next->type & RIGHT_JOIN) == FALSE)
				cur_token->type &= ~RIGHT_JOIN;
			ft_deltoken(&(cur_token->next));
		}
		cur_token = cur_token->next;
	}
}

/*
1. pid($$)확장
2. $확장
3. 필요없는 토큰 지움
4. quote에서 따옴표 지움
5. split해야하는 word의 경우 split해줌
5. word간의 문맥을 보고 필요시 합쳐줌
*/
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
		if (cur_token->next == NULL)
			break ;
		else
			cur_token = cur_token->next;
	}
	remove_trash_token(token_lst);
	quote_remove(token_lst);
	word_split(token_lst);
	word_join(token_lst);
}
