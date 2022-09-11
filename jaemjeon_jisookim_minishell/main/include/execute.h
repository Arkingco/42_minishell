/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/11 12:42:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cmd.h"
# include "env.h"
# include "../libft/libft.h"
# include "utils.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <errno.h>

typedef struct s_exec
{

}	t_exec;

// execute.c
void	execute(t_cmd *cmd, t_envlst *env);


// execute_utils_1.c
int	get_cmd_type(t_cmd *cmd);
char	**get_path_board(t_envlst *env);
char	**get_exec_argv(t_cmd *cmd);

#endif
