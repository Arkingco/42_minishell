/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 13:40:03 by jaemjeon         ###   ########.fr       */
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

# define INPUT_REDI			2
# define OUTPUT_REDI		3
# define INPUT_PIPE			INPUT_REDI
# define OUTPUT_PIPE		OUTPUT_REDI
# define RESTORE_PIPE		RESTORE_REDI
# define MULTI_PIPE_OUTPUT	0
# define MULTI_PIPE_INPUT	1
# define BEFORE_INPUT_FD	2

// execute.c
void	execute(t_working_info *info);

// execute_tools.c
int	ft_open(const char *filename, int flags, short mode);
int	ft_close(int fd);
pid_t	ft_fork(void);
pid_t	ft_wait(int count, pid_t *child_pids);
int	ft_dup2(int fd1, int fd2);
int	ft_pipe(int *pipe_fd);


// execute_utils_1.c
int	get_cmd_type(t_cmd *cmd);
char	**get_path_board(t_envlst *env);
char	**get_exec_argv(t_cmd *cmd);

#endif
