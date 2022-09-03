/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_double_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:58:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/03 17:45:23 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	count_key_value(t_envlst *env)
{
	unsigned int count;

	count = 0;
	if (env->key[count])
		count++;
	return (count);
}

void	make_env_double_ptr(t_exec *exec, t_envlst *env)
{	
	char	*temp;
	char	*ret;
	int		i;

	i = 0;
	exec->env_lst = ft_calloc(1, sizeof(char *) * count_key_value(env));
	while (exec->env->key[i])
	{
		temp = ft_strjoin(env->key, "=");
		if (!(temp))
			exit(1);
		ret = ft_strjoin(temp, env->value);
		if (!(ret))
			exit(1);
		free(temp);
		exec->env_lst[i] = ft_strdup(ret);
		free(ret);
		i++;
	}
}