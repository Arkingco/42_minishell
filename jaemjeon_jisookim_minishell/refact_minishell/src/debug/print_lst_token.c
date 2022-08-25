/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:22 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/25 15:23:47 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_token_type(t_token *token)
{
	printf("flags..\n");
	if (token->type & EXPANDER)
		printf("EXPANDER\n");
	if (token->type & PIPE)
		printf("PIPE\n");
	if (token->type & REDIRECT)
		printf("REDIRECT\n");
	if (token->type & WORD)
		printf("WORD\n");
	if (token->type & READ)
		printf("READ\n");
	if (token->type & HEREDOC)
		printf("HEREDOC\n");
	if (token->type & WRITE)
		printf("WRITE\n");
	if (token->type & WRITE_APPEND)
		printf("WRITE_APPEND\n");
	if (token->type & PURE_WORD)
		printf("PURE_WORD\n");
	if (token->type & EXPANDED)
		printf("EXPANDED\n");
	if (token->type & DQUOTE)
		printf("DQUOTE\n");
	if (token->type & SQUOTE)
		printf("SQUOTE\n");
	if (token->type & LEFT_IFS)
		printf("LEFT_IFS\n");
	if (token->type & RIGHT_IFS)
		printf("RIGHT_IFS\n");
	if (token->type & LEFT_JOIN)
		printf("LEFT_JOIN\n");
	if (token->type & RIGHT_JOIN)
		printf("RIGHT_JOIN\n");
}

void	debug_print_lst_token(t_token *lst)
{
	printf("#######################\n");
	printf("#debug_print_lst_token#\n");
	printf("#######################\n");
	if (lst == NULL)
		printf("PARA_OF_TOKEN_IS_NULL!!");
	while (lst != NULL)
	{
		print_token_type(lst);
		printf("string_value : %s\n", lst->string_value);
		printf("next_p : %p\n prev_p : %p\n", lst->next, lst->prev);
		printf("\n");
		lst = lst->next;
	}
}
