/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_make_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:45:54 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/20 13:34:01 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	make_redirect_tokens(t_token *cur_token)
{
	int	redirect_type;

	redirect_type = cur_token->redirect_type;
	if (redirect_type == E_REDI_L || redirect_type == E_REDI_LL)
	{
		parse_add_redirect_token(ft_tokendup(cur_token), INPUT);
		parse_add_redirect_token(ft_tokendup(cur_token->next), INPUT);
	}
	else if (redirect_type == E_REDI_R || redirect_type == E_REDI_RR)
	{
		parse_add_redirect_token(ft_tokendup(cur_token), OUTPUT);
		parse_add_redirect_token(ft_tokendup(cur_token->next), OUTPUT);
	}
}

void	make_word_token(t_token *cur_token)
{
	parse_add_word_token(ft_tokendup(cur_token));
}

t_cmd	*ft_getlstcmd_last(void)
{
	t_cmd	*last_cmd;

	last_cmd = g_global.lst_cmd;
	if (last_cmd == NULL)
		return (NULL);
	while (last_cmd->next)
		last_cmd = last_cmd->next;
	return (last_cmd);
}

void	parse_add_redirect_token(t_token *token_addr, int io)
{
	static int	gate = FALSE;
	t_redirect	redirect;

	redirect = ft_getlstcmd_last()->redirect;
	token_addr->next = NULL;
	if (io = INPUT)
		ft_token_lstadd_back(&redirect.redirect_input[gate], token_addr);
	else if (io = OUTPUT) 
		ft_token_lstadd_back(&redirect.redirect_output[gate], token_addr);
	if (gate == FALSE)
		gate == TRUE;
	else
		gate = FALSE;
}

void	parse_add_word_token(t_token *token_addr)
{
	t_simple_command *word;

	word = &g_global.lst_cmd->simple_command;
	token_addr->next = NULL;
	ft_token_lstadd_back(&word, token_addr);
}

void	make_cmd_node(t_token *cur_token)
{
	while (cur_token->type != E_PIPE && cur_token->type != E_NULL)
	{
		if (cur_token->type == E_REDIRECT)
		{
			make_redirect_tokens(cur_token);
			cur_token = cur_token->next->next;
		}
		else
		{
			make_word_token(cur_token);
			cur_token = cur_token->next;
		}
	}
}

void	make_cmd_list(void)
{
	t_token	*cur_token;
	t_cmd	*last_cmd;

	cur_token = g_global.lst_token;
	while (cur_token->type != E_NULL)
	{
		if (g_global.lst_cmd == NULL)
			g_global.lst_cmd = ft_calloc(1, sizeof(t_cmd));
		else
		{
			last_cmd = ft_getlstcmd_last();
			last_cmd = last_cmd->next;
			last_cmd = ft_calloc(1, sizeof(t_cmd));
		}
		make_cmd_node(cur_token);
		if (cur_token->type == E_PIPE)
			cur_token = cur_token->next;
	}
}