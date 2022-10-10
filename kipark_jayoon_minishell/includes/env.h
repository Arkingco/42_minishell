/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:21:31 by kipark            #+#    #+#             */
/*   Updated: 2022/10/10 11:06:03 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	char			*str;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// env_key_value.c
char	*get_env_value(t_env *env_head, char *env_key);
char	*get_env_key(char *str);

// env_util.c
int		get_env_key_size(char *env_key);
t_env	*set_shell_env_list(char **envp);

// env_list.c
void	env_add(t_env *env_head, char *env_str);
void	print_env_list(t_env *env_head);

#endif
