/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_working_dir.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:36:01 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 14:25:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORKING_DIR_H
# define T_WORKING_DIR_H

# include "t_env.h"
# include "t_cmd.h"

typedef struct s_working_info
{
	char		*cur_path;
	t_envlst	*env;
	t_cmd		*cmd;
}	t_working_info;


#endif
