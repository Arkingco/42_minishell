/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:11:37 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/21 19:14:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_UTIL_H
 # define VAR_UTIL_H

//main_loop.c
void	loop_get_commandline(void);

// init.c
void	init(int argc, char *envp[]);
void	init_env_lst(char *envp[]);
void	update_shlvl(void);

#endif