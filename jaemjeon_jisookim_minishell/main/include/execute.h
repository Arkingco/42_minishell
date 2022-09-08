/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/08 15:21:25 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cmd.h"
# include "env.h"
# include "../libft/libft.h"
# include "utils.h"
# include <fcntl.h>
# include <sys/dir.h>
# include <sys/stat.h>

// execute.c
void	execute(t_cmd *cmd, t_envlst *env);


// execute_utils_1.c

#endif
