/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:32:29 by kipark            #+#    #+#             */
/*   Updated: 2022/09/22 16:37:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT
# define BUILT

#include"parser.h"

#define CD_SIZE 2
#define EHCO_SIZE 4
#define ENV_SIZE 3
#define EXIT_SIZE 4
#define EXPORT_SIZE 6
#define PWD_SIZE 3
#define UNSET_SIZE 5



int		is_built_in(t_simple_cmd *simple_cmd);
void	execute_bulit_in(t_simple_cmd *simple_cmd, t_env *env);
void	built_in_echo(t_simple_cmd *simple_cmd);
void	built_in_env(t_env *env);
void	built_in_export(t_simple_cmd *simple_cmd, t_env *env);
int		get_equal_location(char *str);

void	built_in_cd();
void	built_in_exit();
void	built_in_pwd();
void	built_in_unset();

#endif