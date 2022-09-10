/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:37:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/10 16:04:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN
# define BUILT_IN

# define BUILT_IN_COUNT 7
# define NOT_BUILT_IN BUILT_IN_COUNT

enum e_type_built_in
{
	T_ECHO = 0,
	T_CD,
	T_PWD,
	T_EXPORT,
	T_UNSET,
	T_ENV,
	T_EXIT
};

// built_ins
void	ft_echo(t_cmd *cmd, t_envlst *env);
void	ft_cd(t_cmd *cmd, t_envlst *env);
void	ft_pwd(t_cmd *cmd, t_envlst *env);
void	ft_export(t_cmd *cmd, t_envlst *env);
void	ft_unset(t_cmd *cmd, t_envlst *env);
void	ft_env(t_cmd *cmd, t_envlst *env);
void	ft_exit(t_cmd *cmd, t_envlst *env);


#endif