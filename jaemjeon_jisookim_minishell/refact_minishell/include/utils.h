/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:04:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 04:52:26 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// error_exit.c
void	ft_error_exit(int exit_status, char *message);

// ifs.c
int	ft_is_ifs(const char *letter);
int	ft_skip_ifs(char **string_pointer);

#endif
