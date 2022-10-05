/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:22:55 by kipark            #+#    #+#             */
/*   Updated: 2022/10/05 13:57:11 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "here_doc.h"
#include "exit_status.h"
#include "execution.h"

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

t_here_doc  *free_all_here_doc(t_here_doc *here_doc, int this_here_doc_fd)
{
	t_here_doc	*this_here_doc;
	t_here_doc	*next;

	if (this_here_doc_fd != 0)
		safe_close(this_here_doc_fd);
	this_here_doc = here_doc;
	while (this_here_doc)
	{
		next = this_here_doc->next;
		if (this_here_doc->read_end != 0)
		{
			// printf("close fd : %d\n", this_here_doc->read_end);
			safe_close(this_here_doc->read_end);
		}
		free(this_here_doc);
		this_here_doc = next;
	}
	return (NULL);
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
