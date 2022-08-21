/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:48:25 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 10:31:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

#include "minishell.h"

// util_1.c
void	ft_error(int exit_status, char *message);
void	ft_free_envp(char **envp);

#endif