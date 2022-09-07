/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_double_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:58:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/06 01:07:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_key_value(t_exec *exec)
{
	unsigned int	count;
	t_exec			*head;

	count = 0;
	head = exec;
	// printf("\n\n"); //debug
	while (exec->env->key && exec->env->next)
	{
		// printf("%s : %s \n", exec->env->key, exec->env->value);
		count++;
		exec->env = exec->env->next;
	}
	// printf("%s : %s \n", exec->env->key, exec->env->value);
	// printf("==========fin? ==============================");
	
	return (count + 1);
}

void	make_env_double_ptr(t_exec *exec)
{	
	void	*env_head;
	char	*temp;
	char	*ret;
	int		i;

	i = 0;
	env_head = exec->env; 
	exec->env_lst = ft_calloc(1, sizeof(char *) * count_key_value(exec));
	
	exec->env = env_head;
	while (exec->env)
	{
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
	exec->env = env_head;
	// i = 0; // debug
	// printf("==========================");
	// while (exec->env_lst[i])
	// {
	// 	printf("[%d] %s\n", i, exec->env_lst[i]);
	// 	i++;
	// }
	// printf("==========================");
}
