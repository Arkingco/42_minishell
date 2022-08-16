/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:12:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/25 02:46:55 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cond	find_node(int fd, t_util **phead, t_util **pcurr)
{
	t_util	*new;

	while (*phead && (*phead)->next && (*phead)->fd != fd)
		phead = &((*phead)->next);
	if (*phead && (*phead)->fd == fd)
	{
		*pcurr = *phead;
		return (SUCCESS);
	}
	new = malloc(sizeof(t_util));
	if (!new)
		return (FAIL);
	new->fd = fd;
	new->index = -1;
	new->next = NULL;
	if (*phead == NULL)
	{
		*phead = new;
		*pcurr = new;
		return (SUCCESS);
	}
	(*phead)->next = new;
	*pcurr = new;
	return (SUCCESS);
}

t_cond	init_string(t_string *ps)
{
	ps->str = malloc(BUFFER_SIZE);
	if (!ps->str)
		return (FAIL);
	ps->len = 0;
	ps->malloc_size = BUFFER_SIZE;
	return (SUCCESS);
}

char	*delete_current_node(int fd, t_util *head, t_util **phead)
{
	t_util	*temp;

	if (!head || fd < 0)
		return (NULL);
	if (head->fd == fd)
	{
		temp = head;
		*phead = head->next;
		free(temp);
		return (NULL);
	}
	while (head->next && head->next->fd != fd)
		head = head->next;
	temp = head->next;
	head->next = head->next->next;
	free(temp);
	return (NULL);
}

char	*free_string(t_string *ps)
{
	free(ps->str);
	ps->str = NULL;
	return (NULL);
}

t_cond	stretch_string(t_string *ps)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(ps->malloc_size <<= 1);
	if (!temp)
		return (FAIL);
	while (i < ps->len)
	{
		temp[i] = (ps->str)[i];
		i++;
	}
	free_string(ps);
	ps->str = temp;
	return (SUCCESS);
}
