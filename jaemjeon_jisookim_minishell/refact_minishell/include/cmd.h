/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:25:57 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 04:51:27 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "token.h"

typedef struct s_cmd
{
	t_token			*simple_cmd;
	t_token			*redirect_input;
	t_token			*redirect_output;
	struct s_cmd	*next;
}	t_cmd;

#endif
