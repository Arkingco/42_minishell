/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:13:04 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 01:20:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_ENV_H
# define VAR_ENV_H

# include "var_enum_def.h"
typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

#endif
