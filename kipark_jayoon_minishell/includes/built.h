/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:32:29 by kipark            #+#    #+#             */
/*   Updated: 2022/09/28 15:55:48 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

# include "parser.h"
# include "execution.h"

int		is_built_in(t_simple_cmd *simple_cmd);
void	execute_bulit_in(t_simple_cmd *simple_cmd, t_env *env, \
										t_execute_cmd_division division_cmd);
int		built_in_echo(t_simple_cmd *simple_cmd);
int		built_in_env(t_env *env);
int		built_in_export(t_simple_cmd *simple_cmd, t_env *env);
int		built_in_pwd(t_simple_cmd *simple_cmd);
int		built_in_unset(t_simple_cmd *simple_cmd, t_env *env);
int		built_in_exit(t_simple_cmd *simple_cmd);
int		built_in_cd(t_simple_cmd *simple_cmd, t_env *env);

#endif