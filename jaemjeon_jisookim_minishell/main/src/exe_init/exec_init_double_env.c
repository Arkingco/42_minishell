/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_double_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:58:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 12:31:43 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_key_value(t_exec *exec, t_envlst *env)
{
	int	count;

	count = 0;
	while (env->key)
	{
		count++;
		if (!env->next)
			break ;
		env = env->next;
	}
	exec->count_key = count;
	return ;
}

void	make_env_double_ptr(t_exec *exec)
{	
	char		*temp;
	char		*ret;
	int			i;
	t_envlst	*env;

	i = 0;
	env = exec->env;
	count_key_value(exec, env);
	exec->env_lst = ft_calloc(1, sizeof(char *) * (exec->count_key + 1));
	while (i < exec->count_key)
	{
		temp = ft_strjoin(env->key, "=");
		if (!(temp))
			exit(1);
		ret = ft_strjoin(temp, env->value);
		if (!(ret))
			exit(1);
		free(temp);
		exec->env_lst[i] = ft_strdup(ret);
		if (!env->next)
			break ;
		env = env->next;
		i++;
	}
	return ;
}
