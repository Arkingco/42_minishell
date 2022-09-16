/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/17 01:18:55 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <errno.h>
# include "cmd.h"
# include "env.h"
# include "../libft/libft.h"
# include "utils.h"
# include "working_dir.h"

enum e_process_mode
{
	IN_MINISHELL_NO_CHILD,
	IN_MINISHELL_HAS_CHILD,
	IN_CHILD,
	IN_HEREDOC
};

// execute.c
void	execute(t_cmd *cmd, t_working_info *info);


// execute_utils_1.c
int	get_cmd_type(t_cmd *cmd);
char	**get_path_board(t_envlst *env);
char	**get_exec_argv(t_cmd *cmd);

#endif
