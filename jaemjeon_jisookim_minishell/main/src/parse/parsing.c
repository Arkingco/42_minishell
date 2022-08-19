/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:45:54 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/19 16:48:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_global	g_global;

void	parsing(char *line)
{
	make_token_list(line);
	make_cmd_list();

}

void	make_token_list(char *line)
{
	//
	// thanks to kipark_jajoon!!
	//
}

void	make_cmd_list(void)
{
	t_token	*cur_token;
	int		redirect_type;

	cur_token = g_global.lst_token;
	while (cur_token->type != E_PIPE)
	{
		if (cur_token->type == E_REDIRECT)
		{
			redirect_type = cur_token->redirect_type;
			if (redirect_type == E_REDI_L || redirect_type == E_REDI_LL)
				parse_add_redirect_token(ft_tokendup(cur_token), INPUT);
			else if (redirect_type == E_REDI_R || redirect_type == E_REDI_RR)
				parse_add_redirect_token(ft_tokendup(cur_token), OUTPUT);
		}
		else
		{
			parse_add_word_token(ft_tokendup(cur_token));
		}
	}
}

void	parse_add_redirect_token(t_token *token_addr, int io)
{
	t_redirect redirect;

	redirect = g_global.lst_cmd->redirect;
	token_addr->next = NULL;
	if (io = INPUT) 
		ft_token_lstadd_back(&redirect.redirect_io[0], token_addr); 
	else if (io = OUTPUT) 
		ft_token_lstadd_back(&redirect.redirect_io[1], token_addr); 
}