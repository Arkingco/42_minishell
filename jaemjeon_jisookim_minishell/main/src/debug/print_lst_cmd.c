/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:53:42 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/29 23:23:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	debug_print_lst_cmd(t_cmd *lst)
{
	int	index;

	index = 1;
	printf("#####################\n");
	printf("#debug_print_lst_cmd#\n");
	printf("#####################\n");
	while (lst != NULL)
	{
		printf("#####################\n");
		printf("#%d'th cmd lst print#\n", index);
		printf("#####################\n\n\n");
		printf("==simple_cmd==\n");
		debug_print_lst_token(lst->simple_cmd);
		printf("==redirect_input==\n");
		debug_print_lst_token(lst->redirect_input);
		printf("==redirect_output==\n");
		debug_print_lst_token(lst->redirect_output);
		printf("\n\n");
		lst = lst->next;
		index++;
	}
}
