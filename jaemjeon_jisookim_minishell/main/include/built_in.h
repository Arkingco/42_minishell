/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:37:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/26 22:45:38 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "structs/t_working_dir.h"
# include "structs/t_cmd.h"

enum	e_type_built_in
{
	T_ECHO = 0,
	T_CD,
	T_PWD,
	T_EXPORT,
	T_UNSET,
	T_ENV,
	T_EXIT,
	T_GOD,
	T_JEONGBLE,
	T_BUILT_IN_COUNT
};

# define BUILT_IN_COUNT T_BUILT_IN_COUNT
# define NOT_BUILT_IN BUILT_IN_COUNT

enum	e_envkey_to_handle
{
	T_SHLVL = 0,
	T_ENVKEY_TO_HANDLE_COUNT
};

# define ENVKEY_TO_HANDLE_COUNT T_ENVKEY_TO_HANDLE_COUNT

// cd_path.c
void	free_cur_path(t_working_info *info);
void	change_info_path(t_cmd *cmd, t_working_info *info, char *path);

// built_ins
int		ft_echo(t_cmd *cmd, t_working_info *info);
int		ft_cd(t_cmd *cmd, t_working_info *info);
int		ft_pwd(t_cmd *cmd, t_working_info *info);
int		ft_export(t_cmd *cmd, t_working_info *info);
int		ft_unset(t_cmd *cmd, t_working_info *info);
int		ft_env(t_cmd *cmd, t_working_info *info);
int		ft_exit(t_cmd *cmd, t_working_info *info);
int		ft_god(t_cmd *cmd, t_working_info *info);
int		ft_jeongble(t_cmd *cmd, t_working_info *info);

// export, unset util
int		check_key_grammar(char *key);

// built_in_utils.c
int		ft_chdir(char *path);
char	*ft_getcwd(char *buf, size_t buf_size);

#endif
