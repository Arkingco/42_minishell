/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:54:31 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 14:54:52 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_token(t_token *lst)
{
	free(lst->string_value);
	lst->string_value = NULL;
	free(lst);
}

void	ft_free_tokenlst(t_token *lst)
{
	t_token	*next_token;

	while (1)
	{
		next_token = lst->next;
		ft_free_token(lst);
		lst = next_token;
		if (lst == NULL)
			return ;
	}
}
