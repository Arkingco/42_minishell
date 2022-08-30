/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:21:31 by kipark            #+#    #+#             */
/*   Updated: 2022/08/30 14:39:38 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
}	t_env;


// env_util*.c
char		*get_env_value(t_env *env_head, char *env_key);
int			get_env_key_size(char *env_key);
t_env		*set_shell_env_list(char **envp);

// env_list*.c
void	set_env_list(t_env *env_head, char **envp);
void	env_add(t_env *env_head, char *env_str);
t_env	*new_env_node(char *env_str);
void	init_env_dummy_node(t_env *new_env);
void	print_env_list(t_env *env_head);

#endif