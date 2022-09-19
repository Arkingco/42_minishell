/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 01:40:16 by jaemjeon         ###   ########.fr       */
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

# define INPUT_REDI		2
# define OUTPUT_REDI	3
# define INPUT_PIPE		INPUT_REDI
# define OUTPUT_PIPE	OUTPUT_REDI
# define RESTORE_PIPE	RESTORE_REDI

// execute.c
void	execute(t_working_info *info);

// execute_tools.c
int	ft_open(const char *filename, int flags, short mode);
int	ft_close(int fd);
pid_t	ft_fork(void);


// execute_utils_1.c
int	get_cmd_type(t_cmd *cmd);
char	**get_path_board(t_envlst *env);
char	**get_exec_argv(t_cmd *cmd);

#endif
