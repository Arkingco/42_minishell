/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:32:29 by kipark            #+#    #+#             */
/*   Updated: 2022/09/25 14:07:18 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT
# define BUILT

#include"parser.h"

int		is_built_in(t_simple_cmd *simple_cmd);
void	execute_bulit_in(t_simple_cmd *simple_cmd, t_env *env);
void	built_in_echo(t_simple_cmd *simple_cmd);
void	built_in_env(t_env *env);
void	built_in_export(t_simple_cmd *simple_cmd, t_env *env);
void	built_in_pwd();
void	built_in_unset(t_simple_cmd *simple_cmd, t_env *env);
void	built_in_exit(t_simple_cmd *simple_cmd);
void	built_in_cd(t_simple_cmd *simple_cmd, t_env *env);


#endif