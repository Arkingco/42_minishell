/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_double_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:58:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:13:55 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_key_value(t_exec *exec)
{
	unsigned int	count;
	t_exec			*head;

	count = 0;
	head = exec;
	exec->env = exec->env_head;
	while (exec->env->key && exec->env->next)
	{
		count++;
		exec->env = exec->env->next;
	}
	exec->env = exec->env_head;
	return (count + 1);
}

void	make_env_double_ptr(t_exec *exec)
{	
	char	*temp;
	char	*ret;
	int		i;

	i = 0;
	exec->count_key = (int)count_key_value(exec);
	exec->env_lst = ft_calloc(1, sizeof(char *) * (exec->count_key + 1));
	exec->env_lst[exec->count_key] = NULL;
	
	while (i < exec->count_key)
	{
		// printf("key : %s\n", exec->env->key);
		// printf("value : %s\n", exec->env->value);

		temp = ft_strjoin(exec->env->key, "=");
		if (!(temp))
			exit(1);
		ret = ft_strjoin(temp, exec->env->value);
		if (!(ret))
			exit(1);
		free(temp);
		exec->env_lst[i] = ft_strdup(ret);
		exec->env = exec->env->next;
		i++;
	}
	exec->env = exec->env_head;
	// i = 0; // debug
	// printf("\n\n=========== ENV_DEBUG ===============\n");
	// while (i < exec->count_key)
	// {
	// 	printf("[%d] %s\n", i, exec->env_lst[i]);
	// 	i++;
	// }
	// printf("\n=========== ENV_DEBUG ===============\n\n");
	return ;
}
