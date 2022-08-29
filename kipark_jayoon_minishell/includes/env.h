/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:21:31 by kipark            #+#    #+#             */
/*   Updated: 2022/08/27 16:17:40 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
}	t_env;


char		*get_env_value();
int			get_env_key_size(char *env_key);
t_env		*set_shell_env_list(char **envp);

#endif