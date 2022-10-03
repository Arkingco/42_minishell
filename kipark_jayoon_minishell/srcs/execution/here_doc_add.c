/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:22:55 by kipark            #+#    #+#             */
/*   Updated: 2022/10/03 17:44:55 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "here_doc.h"
#include "exit_status.h"

t_here_doc	*new_here_doc(int fd)
{
	t_here_doc *here_doc;

	here_doc = ft_safe_malloc(sizeof(t_here_doc));
	here_doc->read_end = fd;
	here_doc->next = NULL;
	return (here_doc);
}

void	add_here_doc(t_here_doc *here_doc, int fd)
{
	t_here_doc *this_here_doc;

	this_here_doc = here_doc;
	while (this_here_doc->next != NULL)
		this_here_doc = this_here_doc->next;
	this_here_doc->next = new_here_doc(fd);
}

void  free_all_here_doc(t_here_doc *here_doc)
{
	t_here_doc	*here_this_token;
	t_here_doc	*next;

	here_this_token = here_doc;
	while (here_this_token)
	{
		next = here_this_token->next;
		free(here_this_token);
		here_this_token = next;
	}
	return ;
}

void  print_here_doc(t_here_doc *here_doc)
{
	t_here_doc	*this_here_doc;

	this_here_doc = here_doc->next;
	while (this_here_doc)
	{
		printf("here_doc fd : %d\n", this_here_doc->read_end);
		this_here_doc = this_here_doc->next;
	}
}
