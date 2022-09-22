/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:33:41 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 00:34:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
			free(cur_token->next->string_value);
			cur_token->next->string_value = joined_string;
			cur_token = cur_token->next;
			if (cur_token->prev->prev == NULL)
				*token_lst = cur_token;
			ft_deltoken(&(cur_token->prev));
		}
		else
			cur_token = cur_token->next;
	}
}

void	combine_redirect_filename(t_token *token_lst)
{
	t_token	*cur_token;

	cur_token = token_lst;
	while (cur_token != NULL && cur_token->next != NULL)
	{
		if (cur_token->type & REDIRECT)
		{
			cur_token->string_value = ft_strdup(cur_token->next->string_value);
			if (cur_token->string_value == NULL)
				ft_error_exit(1, "malloc failed in ft_strdup in combine_token");
			cur_token->type |= cur_token->next->type & QUOTE;
			ft_deltoken(&cur_token->next);
		}
		cur_token = cur_token->next;
	}
}

t_cmd	*token_to_cmd(t_token *token_lst)
{
	t_token	*cur_token;
	t_token	*next_token;
	t_cmd	*cur_cmd;
	t_cmd	*first_cmd;

	cur_token = token_lst;
	first_cmd = make_cmd_linkedlst(token_lst);
	cur_cmd = first_cmd;
	while (cur_token != NULL)
	{
		next_token = cur_token->next;
		if (cur_token->type & PIPE)
		{
			cur_cmd = cur_cmd->next;
			ft_free_token(cur_token);
		}
		else if (cur_token->type & REDIRECT)
		{
			if (cur_token->type & (READ | HEREDOC))
				ft_token_lstadd_back(&cur_cmd->redirect_input, cur_token);
			else
				ft_token_lstadd_back(&cur_cmd->redirect_output, cur_token);
		}
		else
			ft_token_lstadd_back(&cur_cmd->simple_cmd, cur_token);
		cur_token = next_token;
	}
	return (first_cmd);
}

void	remove_trash_token(t_token **token_lst)
{
	t_token	*cur_token;
	t_token	*head_token;
	t_token	*to_del_token;

	cur_token = *token_lst;
	head_token = *token_lst;
	while (cur_token != NULL)
	{
		if ((cur_token->type & EXPANDER) && \
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
