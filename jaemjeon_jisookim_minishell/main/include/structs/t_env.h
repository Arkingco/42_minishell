/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:37:22 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/21 13:37:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_H
# define T_ENV_H

typedef struct s_envlst
{
	char			*key;
	char			*value;
	int				has_value;
	struct s_envlst	*next;
	struct s_envlst	*prev;
}	t_envlst;

#endif
