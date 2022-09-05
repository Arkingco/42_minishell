/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:04:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/29 04:06:42 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// error_exit.c
void	ft_error_exit(int exit_status, char *message);

// ifs.c
int	ft_has_ifs(char *string);
int	ft_is_ifs(const char *letter);
int	ft_skip_ifs1(char **string_pointer);
void	ft_skip_ifs2(char *line, int *index);

#endif
