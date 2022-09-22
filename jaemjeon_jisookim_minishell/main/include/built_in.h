/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:37:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 14:41:48 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN
# define BUILT_IN

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

// built_ins
void	ft_echo(t_cmd *cmd, t_working_info *info);
void	ft_cd(t_cmd *cmd, t_working_info *info);
void	ft_pwd(t_cmd *cmd, t_working_info *info);
void	ft_export(t_cmd *cmd, t_working_info *info);
void	ft_unset(t_cmd *cmd, t_working_info *info);
void	ft_env(t_cmd *cmd, t_working_info *info);
void	ft_exit(t_cmd *cmd, t_working_info *info);

// built_in_utils.c
int		ft_chdir(char *path);
char	*ft_getcwd(char *buf, size_t buf_size);


#endif
