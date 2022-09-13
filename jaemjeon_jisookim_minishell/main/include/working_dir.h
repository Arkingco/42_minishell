/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_dir.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:12:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/14 02:49:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKING_DIR
# define WORKING_DIR

# include <stdio.h>
# include <dirent.h>
# include "env.h"

typedef struct s_working_info
{
	char		*cur_path;
	DIR			*dp;
	t_envlst	*env;
}	t_working_info;

#endif