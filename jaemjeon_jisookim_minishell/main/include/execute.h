/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/10 20:32:05 by jaemjeon         ###   ########.fr       */
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

// execute.c
void	execute(t_cmd *cmd, t_envlst *env);


// execute_utils_1.c
int	get_cmd_type(t_cmd *cmd)
char	**get_path_board(t_envlst *env)
char	*get_excv_path(char *cmd_string, t_envlst *env)

#endif
